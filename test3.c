#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 20
typedef char element;
typedef struct{
	int top;
	element data[STACK_SIZE];
}Stack;

int checkTest(char expr[]);
void initStack( Stack *s );
int isFull( Stack *s );
int isEmpty( Stack *s );
void push( Stack *s, element data );
element pop( Stack *s );

int main(){
	int i;
	Stack s;
	char expr[20];
	
	printf("괄호포함 수식 입력 : ");
	scanf("%s", expr);
	if (checkTest(expr)) printf("성공");
	else printf("실패");
	return 0;
	
}
void initStack( Stack *s ){  // top 포인터를 -1로 초기화
	s->top = -1;
}
int isFull( Stack *s ){   // 스택이 가득 차 있으면 true 리턴
	return s->top == STACK_SIZE-1;
	
}
int isEmpty( Stack *s ){   // 스택이 비어 있으면 true 리턴
	return s->top == -1;
}
void push( Stack *s, element data ){ //스택이 가득 차 있으면 문구 출력 후 리턴, 아니면 push
	if(isFull(s)){
		printf("Stack is Full\n");
		exit(0);
	}
	s->top++;
	s->data[s->top] = data;
}
element pop( Stack *s ){  //스택이 비어  있으면 문구 출력 후 0 리턴, 아니면 맨 위 데이터 리턴
	if(isEmpty(s)){
		printf("Stack is Full\n");
		exit(0);
	}
	return s->data[s->top--];
}
int checkTest(char expr[]){
	int i;
	Stack s;
	initStack(&s);
	char ch,open_ch;
  for(i=0;expr[i]!='\0';i++){
		ch = expr[i];
		//코드작성
		switch(ch){
			case '(': 
			case '[':
			case '{':
			//코드작성
			push(&s,ch);
				break;
			case ')':
			case ']':
			case '}':	
				if (isEmpty(&s)) return 0;
				open_ch = pop(&s);
				//코드작성
				if ((open_ch == '(' && ch != ')') ||
					  (open_ch == '[' && ch != ']') ||
					  (open_ch == '{' && ch != '}') ) {
					return 0;
				}
				//printf("open_ch=%c\n",open_ch);
				break;
		}
	}
	if (!isEmpty(&s)) return 0;
	return 1;
}
