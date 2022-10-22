#include <stdio.h>
int num2[1000001];
int k(long long int f){
    if(f==1) return 1;
    else if(f==2) return 2;
    else if(f==3) return 4;
    else if(num2[f]!=0) return num2[f];
    else return num2[f] = (k(f-1)+k(f-2)+k(f-3))%1000;
}
int main(){
    long long int num1;
    scanf("%lld",&num1);
    printf("%d\n",k(num1));
    return 0;
}
