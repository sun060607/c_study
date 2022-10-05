#include <stdio.h>
#include <math.h>
#define N 5
typedef struct point{
	int x,  y;
}POINT;

void inputPoint( POINT *p );
void outputPoint( POINT *p );
double distance( POINT *p, POINT *q);

int main() {
	int i,j,mi = 0;
	POINT p[5];
	POINT origin = { 0, 0};
	// 여기에 코드 추가
	//1. 5게 입력,출력
	//2. 5개 거리 계산
	//3. 5개의 거리계산 하면서 제일 작은 거리 계산
	
	for(i = 0;i<5;i++){
		inputPoint(p+i);//&p[i]
	}
	//for(i = 0;i<5;i++){
		//outputPoint(&p[i]);
	//}
	for(i=1;i<5;i++){
		if(distance(&p[mi].x,&origin.x) >=distance(&p[i].x,&origin.x)){
			if(p[mi].x+p[mi].y > p[i].x+p[i].y ){
				mi = i;
			}
		}
	}
	
	printf("원점에서 가장 가까운 좌표 : (%4d, %4d)", p[mi].x,p[mi].y);
	return 0;
}
void inputPoint( POINT *p){
	scanf("%d %d",&p->x,&p->y);
	
}
	
void outputPoint( POINT *p ){
	printf("%d %d",p->x,p->y);
	
}
double distance( POINT *p, POINT *q){
	return sqrt(pow(p->x - q->x,2)+(p->y - q->y,2));
}