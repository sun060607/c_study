#include <stdio.h>
int main(){
    int num,num1,num2=1,num3=1,num5=1;
    scanf("%d %d",&num,&num1);
    int num4 = num-num1;
    for(int i=num;i>=1;i--){
        num2=num2*i;
    }
    for(int i=num1;i>=1;i--){
        num3=num3*i;
    }
    for(int i=num4;i>=1;i--){
        num5=num5*i;
    }
    printf("%d",num2/(num3*num5));
    return 0;
}
