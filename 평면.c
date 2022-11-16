#include <stdio.h>
int num1[1000000]={1,2,4};
int f(int n){
    if(num1[n]) return num1[n];
    return num1[n] = (f(n;ㅑ-1)+n)%137;
}
int main(){
    int num;
    scanf("%d",&num);
    printf("%d",f(num));
    
    return 0;
}
