#include <stdio.h>
int num1[10000001]={1};
int main(void){
    int num;
    scanf("%d",&num);
    for(int i=1;i<=num;i++){
        num1[i] = ((num1[i-1])+i)%137;
    }
    printf("%d",num1[num]);
    
    return 0;
}
