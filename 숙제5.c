#include <stdio.h>
int main() {
	char num1[15];
	int num2;
	scanf("%s",num1);
	num2 = (num1[0]-48)*10+(num1[1]-48);
	if(num1[7]=='1'||num1[7]=='2'){
		num2 = 2019 - (1900+num2)+1;
		if(num1[7]=='1'){
			printf("%d M",num2);
		}else if(num1[7]=='2'){
			printf("%d W",num2);
		}
	}else if(num1[7]=='3'||num1[7]=='4'){
		num2 = 2019 - (2000+num2)+1;
		if(num1[7]=='3'){
			printf("%d M",num2);
		}else if(num1[7]=='4'){
			printf("%d W",num2);
		}
	}
	return 0;
}
