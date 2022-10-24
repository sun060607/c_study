// 함수를 활용해 node 동적으로 생성하기
#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct Node {
    element data;
    struct Node* next;
}Node;
Node *createNode( element data );
void printAll( Node *ptr );

int main(){
    Node *head, *node1,*node2,*node3;
	  node1 = createNode(12);
		node2 = createNode(99);
		node3 = createNode(37);
		node1->next = node2;
	node2->next = node3;
		head = node1;
		printAll(head);
}
Node *createNode( element data){
    //노드 크기 동적 할당
	Node *newNode = (Node*)malloc(sizeof(Node));
	
	newNode->data = data;
    //노드의 데이터 저장
    //노드->next 참조를 NULL저장
	newNode->next = NULL;
	
	return newNode;
}
void printAll( Node* ptr ){
    while( ptr != NULL ){
				if (ptr->next){//next 노드가 있으면 ->출력
          //노드의 데이터 출력 
        	//다음노드의 주소로 저장
					printf("%d->",ptr->data);
					ptr = ptr->next;
				}
			  else {
					printf("%d",ptr->data);
					return;//프린트 종료
				}
    }
}