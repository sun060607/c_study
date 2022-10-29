#include <stdio.h>
int num1=0;
int k(int f){
    if(f==1) return 1;
    else if(f==2) return 1 + k(1);
    else return k(f-2)+k(f-1);
}
int main(){
    scanf("%d",&num1);
    printf("%d",k(num1));
    return 0;
}
