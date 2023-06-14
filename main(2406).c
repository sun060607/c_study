/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#define MODE_A	  1
#define MODE_B	  2
#define MODE_C	  3
#define MODE_OFF  4

volatile uint8_t mode;
uint8_t RxBuffer[1];
uint8_t message_1[] = "\n\n***********************\n";
uint8_t message_2[] = "Light Control\n";
uint8_t message_3[] = "***********************\n\n";
uint8_t message_4[] = "[A] mode\n";
uint8_t message_5[] = "[B] mode\n";
uint8_t message_6[] = "[C] mode\n";
uint8_t message_7[] = "[D] mode\n\n";
uint8_t message_8[] = "mode number : ";
uint8_t message_9[] = "\n\nNow, [A] mode!\n";
uint8_t message_10[] = "\n\nNow, [B] mode!\n";
uint8_t message_11[] = "\n\nNow, [C] mode!\n";
uint8_t message_12[] = "\n\nNow, [D] mode!\n";
uint8_t message_13[] = "\n\nSelect number : 1 ~ 4\n";

void display_menu() {
	HAL_UART_Transmit(&huart2, message_1, sizeof(message_1), 100);
	HAL_UART_Transmit(&huart2, message_2, sizeof(message_2), 100);
	HAL_UART_Transmit(&huart2, message_3, sizeof(message_3), 100);
	HAL_UART_Transmit(&huart2, message_4, sizeof(message_4), 100);
	HAL_UART_Transmit(&huart2, message_5, sizeof(message_5), 100);
	HAL_UART_Transmit(&huart2, message_6, sizeof(message_6), 100);
	HAL_UART_Transmit(&huart2, message_7, sizeof(message_7), 100);
	HAL_UART_Transmit(&huart2, message_8, sizeof(message_8), 100);
}
typedef struct led {
	GPIO_TypeDef *port;
	uint16_t pin;
} LED;
LED led[8] = { { GPIOC, GPIO_PIN_3 }, { GPIOC, GPIO_PIN_2 }, { GPIOC,
GPIO_PIN_1 }, { GPIOC, GPIO_PIN_0 }, { GPIOB, GPIO_PIN_15 }, {
GPIOB, GPIO_PIN_14 }, { GPIOB, GPIO_PIN_13 }, { GPIOB,
GPIO_PIN_12 }, };

void led_all_off() {
	for (uint8_t k = 0; k < 8; k++) {
		HAL_GPIO_WritePin(led[k].port, led[k].pin, GPIO_PIN_RESET);
	}
}
void mode_a() {
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 1) {
			HAL_GPIO_WritePin(led[i].port, led[i].pin, GPIO_PIN_SET);
		}
	}
	if (mode == MODE_B || mode == MODE_OFF || mode == MODE_C) {
		led_all_off();
		return;
	}
	HAL_Delay(500);
	for (int i = 0; i < 8; i++) {
			if (i % 2 == 1) {
				HAL_GPIO_WritePin(led[i].port, led[i].pin, GPIO_PIN_RESET);
		}
	}
	if (mode == MODE_B || mode == MODE_OFF || mode == MODE_C) {
			led_all_off();
			return;
		}
	HAL_Delay(500);
}
void mode_b() {
	HAL_GPIO_WritePin(led[3].port, led[3].pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(led[4].port, led[4].pin, GPIO_PIN_SET);
	HAL_Delay(500);
	HAL_GPIO_WritePin(led[3].port, led[3].pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(led[4].port, led[4].pin, GPIO_PIN_RESET);
	if (mode == MODE_A || mode == MODE_OFF || mode == MODE_C) {
		led_all_off();
		return;
	}

	HAL_GPIO_WritePin(led[2].port, led[2].pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(led[5].port, led[5].pin, GPIO_PIN_SET);
	HAL_Delay(500);
	HAL_GPIO_WritePin(led[3].port, led[2].pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(led[4].port, led[5].pin, GPIO_PIN_RESET);
	if (mode == MODE_A || mode == MODE_OFF || mode == MODE_C) {
		led_all_off();
		return;
	}

	HAL_GPIO_WritePin(led[3].port, led[1].pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(led[4].port, led[6].pin, GPIO_PIN_SET);
	HAL_Delay(500);
	HAL_GPIO_WritePin(led[3].port, led[1].pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(led[4].port, led[6].pin, GPIO_PIN_RESET);
	if (mode == MODE_A || mode == MODE_OFF || mode == MODE_C) {
		led_all_off();
		return;
	}

	HAL_GPIO_WritePin(led[3].port, led[0].pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(led[4].port, led[7].pin, GPIO_PIN_SET);
	HAL_Delay(500);
	HAL_GPIO_WritePin(led[3].port, led[0].pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(led[4].port, led[7].pin, GPIO_PIN_RESET);
	if (mode == MODE_A || mode == MODE_OFF || mode == MODE_C) {
		led_all_off();
		return;
	}
}
void mode_c() {
	for (int i = 0; i < 8; i++) {
		HAL_GPIO_WritePin(led[i].port, led[i].pin, GPIO_PIN_SET);
	}
	if (mode == MODE_B || mode == MODE_OFF || mode == MODE_A) {
			led_all_off();
			return;
	}
	HAL_Delay(1000);
	for (int i = 0; i < 8; i++) {
		HAL_GPIO_WritePin(led[i].port, led[i].pin, GPIO_PIN_RESET);
	}
	if (mode == MODE_B || mode == MODE_OFF || mode == MODE_A) {
		led_all_off();
		return;
	}
	HAL_Delay(1000);
}
/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_USART2_UART_Init();
	/* USER CODE BEGIN 2 */
	display_menu();
	HAL_UART_Receive_IT(&huart2, RxBuffer, 1);
	/* USER CODE END 2 */
	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1) {
		/* USER CODE END WHILE */
		if (mode == MODE_A)
			mode_a();
		else if (mode == MODE_B)
			mode_b();
		else if (mode == MODE_C)
			mode_c();
		else
			led_all_off();
		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
	RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief USART2 Initialization Function
 * @param None
 * @retval None
 */
static void MX_USART2_UART_Init(void) {

	/* USER CODE BEGIN USART2_Init 0 */

	/* USER CODE END USART2_Init 0 */

	/* USER CODE BEGIN USART2_Init 1 */

	/* USER CODE END USART2_Init 1 */
	huart2.Instance = USART2;
	huart2.Init.BaudRate = 115200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(&huart2) != HAL_OK) {
		Error_Handler();
	}
	/* USER CODE BEGIN USART2_Init 2 */

	/* USER CODE END USART2_Init 2 */

}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	/* USER CODE BEGIN MX_GPIO_Init_1 */
	/* USER CODE END MX_GPIO_Init_1 */

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3,
			GPIO_PIN_RESET);

	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB,
	GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, GPIO_PIN_RESET);

	/*Configure GPIO pins : PC0 PC1 PC2 PC3 */
	GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	/*Configure GPIO pins : PB12 PB13 PB14 PB15 */
	GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	/* USER CODE BEGIN MX_GPIO_Init_2 */
	/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	switch (RxBuffer[0]) {
	case '1':
		mode = MODE_A;
		HAL_UART_Transmit(&huart2, RxBuffer, sizeof(RxBuffer), 100);
		HAL_UART_Transmit(&huart2, message_9, sizeof(message_9), 100);
		display_menu();
		break;
	case '2':
		mode = MODE_B;
		HAL_UART_Transmit(&huart2, RxBuffer, sizeof(RxBuffer), 100);
		HAL_UART_Transmit(&huart2, message_10, sizeof(message_10), 100);
		display_menu();
		break;
	case '3':
		mode = MODE_C;
		HAL_UART_Transmit(&huart2, RxBuffer, sizeof(RxBuffer), 100);
		HAL_UART_Transmit(&huart2, message_11, sizeof(message_11), 100);
		display_menu();
		break;
	case '4':
		mode = MODE_OFF;
		HAL_UART_Transmit(&huart2, RxBuffer, sizeof(RxBuffer), 100);
		HAL_UART_Transmit(&huart2, message_12, sizeof(message_12), 100);
		display_menu();
		break;
	default:
		RxBuffer[0] = '\a';
		HAL_UART_Transmit(&huart2, RxBuffer, sizeof(RxBuffer), 100);
		HAL_UART_Transmit(&huart2, message_13, sizeof(message_13), 100);
		display_menu();
		break;
	}
	HAL_UART_Receive_IT(&huart2, RxBuffer, 1);
}
/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
	}
	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
