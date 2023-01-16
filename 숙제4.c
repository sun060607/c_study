#include <stdio.h>
int main() {
	int num1,num3=0,num4=200;
	int num2[101];
	scanf("%d",&num1);
	for(int i=0;i<num1;i++){
		scanf("%d",&num2[i]);
	}
	for(int i=0;i<num1;i++){
		if(num3<num2[i]){
			num3=num2[i];
		}
	}
	for(int i=0;i<num1;i++){
		if(num4>num2[i]){
			num4=num2[i];
		}
	}
	printf("%d",(num3-num4));
	return 0;
}
