#include <stdio.h>
#include <stdlib.h>
typedef int element;
//1)Node구조체 작성
typedef struct Node{
   element data;
   struct Node* next;
}Node;

void printList(Node* head){
   Node *ptr = head->next;
   int cnt = 0;
   if (head == NULL) return;
   do {
      if(ptr == NULL) break;
      //2)데이터 출력
      printf("%d->",ptr->data);
      //3)ptr을 다음 주소로 저장
      ptr = ptr->next;
      cnt++;
   }while(cnt<10);//4)조건

   printf("\n");
}
Node* insertFirst(Node* head, element data){
   Node* node = (Node*)malloc(sizeof(Node));
   node->data = data;
   if (head == NULL){
      head = node;// head의 주소로 새로운노드의 주소 저장
      head->next = head;//새로운노드의 다음 주소로 head 저장
   }
   else{
      node->next= head->next;//head->next 저장    
      head->next= node;//head의 다음노드 주소로 새로운노드의 주소 저장
   }
   return head;
}
Node* insertLast(Node* head, element data){
   Node* node = (Node*)malloc(sizeof(Node));
   node->data =data;
   if (head == NULL){
      head = node;//새로운노드의 다음 주소로 head 저장
      head->next = node;// head의 주소로 새로운노드의 주소 저장
   }
   else{
      node->next = head->next;
      head->next = node;
      head = node;
   }
   return head;
}
int main() {
   Node *head=NULL, *tail, *ptr;
   printf("처음위치에 연결\n");
   for(int i = 1;i< 5;i++){
      head = insertFirst(head,i);   
   }
   printList(head);
   printf("마지막위치에 연결\n");
   for(int i = 11;i< 15;i++){
      head = insertLast(head,i);   
   }
   printList(head);

   return 0;
}

