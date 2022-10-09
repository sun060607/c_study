#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 20

typedef char element;
//스택 구조체 작성
typedef struct{
	int top;
	element data[STACK_SIZE];
}Stack;
void initStack( Stack *s );
int isFull( Stack *s );
int isEmpty( Stack *s );
void push( Stack *s, element data );
element pop( Stack *s );

int main(){
	int i;
 	Stack s;
	char str[20];
	initStack(&s);
	printf("문자열 입력 : ");
	scanf("%s", str); // hello
	for(i=0;str[i]!='\0';i++){
		push(&s,str[i]);
	}
	for(i=0;str[i]!='\0';i++){
		printf("%c",pop(&s));
	}
	//문자열을 입력받아 거꾸로 출력
	
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