#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define STACK_SIZE 100
#define SEARCH_SIZE 100
int main(){
    char searchvalue[100];
    char line[100];
    char num1[101];
    char f;
    int num;
   int i;
   for(i=1;i<=11;i++){
        sprintf(num1,"search/%d.txt",i);
        FILE* fp = fopen(num1,"r");
        while(fgets(line,100, fp)){//줄별로 읽기
            printf("%s",line);
        }
        Sleep(1000);
        printf("\n");
    }
    i-=1;
    while (1){
        printf("방향키를 입력하여 정보 스크롤\n");
        int key = _getch();
        if(i>11){
            printf("초과 하였습니다.\n");
        }
        if(key==72){
            i-=1;
            sprintf(num1,"search/%d.txt",i);
            FILE* fp = fopen(num1,"r");
            while(fgets(line,100, fp)){//줄별로 읽기
                printf("%s",line);
            }
            Sleep(1000);
            printf("\n");
        }
        else if(key == 80){
            i+=1;
            sprintf(num1,"search/%d.txt",i);
            FILE* fp = fopen(num1,"r");
            while(fgets(line,100, fp)){//줄별로 읽기
                printf("%s",line);
            }
            Sleep(1000);
            printf("\n");
        }
    }
    return 0;
}
