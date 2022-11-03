#include <stdio.h>
int main() {
	int num1,num3=0,num4=0;
	int num2[100]={};
	int i;
	scanf("%d",&num1);
	for(i=0;i<num1;i++){
		scanf("%d",&num2[i]);
	}
	scanf("%d",&num3);
	for(i=0;i<num1;i++){
		num4++;
		if(num2[i]==num3){
			break;
		}
	}
	if(i==5){
		printf("실패");
	}else {printf("%d",num4);}
	return 0;
}
