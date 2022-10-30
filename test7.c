#include <stdio.h>
void p(int num3,int num4){
    if(num3>num4){
        return;
    }
    if(num3%2==1){
        printf("%d ",num3);
    }
    p(num3+1,num4);
}
int main(){
    int num1,num2;
    scanf("%d %d",&num1,&num2);
    p(num1,num2);
    
    return 0;
}
