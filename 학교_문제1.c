#include <stdio.h>
int main() {
	int num1,num2,num3=0;
	scanf("%d %d",&num1,&num2);
	for(int i=1;i<=num1;i++){
		if(i%num2==0){
			num3+=i;
		}
	}
	printf("%d",num3);
	return 0;
}
