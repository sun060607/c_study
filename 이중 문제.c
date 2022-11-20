#include <stdio.h>
#include <stdlib.h>
//이중연결 노드 구조체 정의
//이중연결리스트 Head 구조체 정의

void insertNode(Head* head, int data);
void deleteNode(Head* head);
int main(){
	Head* head = (Head*)malloc(sizeof(head)); // 연결 리스트의 헤더 생성
	head->link = NULL;
	head->size = 0;
	// 원형 이중 연결 리스트 사이즈(풍선개수)를 입력
  int size,num;
	scanf("%d", &size);
  //숫자를 입력받아 리스트에 풍선노드 추가
	for (int i = 0; i < size; i++){
		scanf("%d", &num);
 		//리스트에 노드에 삽입 함수 호출
	}
 for (int i = 0; i < size; i++){
		//리스트 노드 삭제
	}
	free(head->link);
	free(head);
  return 0;
}

void InsertNode(Head* head, int data)
{
	// 리스트에 새로 추가될 노드
	DNode* newNode = //동적할당
	newNode->data = data;
	newNode->index =//리스트 크기 +1

	// 리스트 마지막 위치에 노드 삽입
	if (head->link == NULL){ //리스트에 최초삽입시 초기화
		head->link = //;
		newNode->prev = //;
		newNode->next = //;
	}
	else{	
    newNode->prev = //
	  head->link->prev->next = //
		newNode->next = //
		head->link->prev = //
		}
	// 리스트 사이즈를 증가시켜 인덱스로 활용
	head->size++;
}

void deleteNode(Head* head){
	int index = // / 풍선의 번호
	int count = //풍선 안에 들어 있는 숫자의 값
	printf("%d ", index);
	// 풍선이 하나 남아 있을 때 종료
	if (head->size == 1){
		head->size--;
		return;
	}
	// 삭제할 풍선을 가리키는 노드
	DNode* removed =  // 삭제할 노드 주소 저장
	DNode* p =//순회할 시작 주소 저장
	if (count > 0){ //양수일때
		for (int i = 0; i < count; i++){
			p = //다음노드 방향으로 이동
			if (p == removed){//터트릴 풍선 skip
				p = p->next;
			}
		}
	}
	else
	{
		for (int i = 0; i < count * (-1); i++){
			p =  //음수일때 이전 노드 방향 이동
		 // 탐색 한 위치가 삭제할 노드이면  skip
			if (p == /* */){
				p = //
			}
		}
	}
	head->link =  //마지막 순회한 위치를 새로운 head 주소로 저장
	removed->prev->next = //삭제할 다음노드와 연결
	removed->next->prev = //삭제할 이전노드와 연결  
  free(removed);
	head->size--;
}
