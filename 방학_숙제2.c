#include <stdio.h>
int main() {
	int num1,num2,num3=0;
	scanf("%d %d",&num1,&num2);
	for(int i=num1;i<=num2;i++){
		if(i==num1){
			printf("%d ",i);
			num3+=i;
		}else{
			printf("+ %d ",i);
			num3+=i;
		}
	}
	printf("= %d",num3);
	return 0;
}
