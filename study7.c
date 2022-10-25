// 동적으로 구조체 생성하기
#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct Node{
	element data;
	struct Node *next;
}Node;
int main(){
	 Node *n1, *n2 ,*n3, *head;
    n1 =(Node *)malloc(sizeof(Node));
    n2 = (Node *)malloc(sizeof(Node));
		n3 = (Node *)malloc(sizeof(Node));
		//printf("n1=%p n2=%p n3=%p",n1,n2,n3);
		n1->data = 10;
		n1->next = n2;
	  n2->data = 20;
		n2->next = n3;
	  n3->data = 30;
		n3->next = NULL;
    //2) n1의 데이터에 10을 저장
    //3) n1의 다음 노드 주소 next에 n2를 저장
 		//4) n2의 데이터에 20을 저장
		//5)n2의 다음 노드 주소 next에 n3 저장
  	//6) n3의 데이터에 30을 저장
		//7) n3의 다음 노드 주소 next에 NULL 저장
    head = n1;//8)n1의 주소 저장(참조)
    while( head !=NULL){
        printf("%d->", head->data);
       //9) head에 다음 노드 주소 저장
			  head = head->next;
    }
}
