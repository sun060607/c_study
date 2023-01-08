#include <stdio.h>
int main() {
	int num1,num2=0;
	scanf("%d",&num1);
	for(int i=1;i<num1;i++){
		if(i==1){
			printf("%d ",i);
			num2+=i;
		}else if(num1%i==0){
			printf("+ %d ",i);
			num2+=i;
		}
	}
	printf("= %d",num2);
	return 0;
}
