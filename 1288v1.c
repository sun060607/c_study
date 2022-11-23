#include <stdio.h>
int su[26][26];
int f(int n,int m){
    if(n==m||m==0) return 1;
    if(m==1) return n;
    if(n<m) return 0;
    return su[n][m] = f(n-1,m-1)+f(n-1,m);
}
int main(){
    int num,num1;
    scanf("%d %d",&num,&num1);
    
    printf("%d",f(num,num1));
    return 0;
}
