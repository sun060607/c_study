#include <stdio.h>
int main(){
    int su[26][26];
    int num,num1,i,j;
    scanf("%d %d",&num,&num1);
    for(i=0;i<=num1;i++){
        for(j=0;j<=num;j++){
            if(j==0) su[j][i]=0;
            else if(i==0) su[j][i]=1;
            else if(i==j) su[j][i]=1;
            else if(su[j][i]==0) su[j][i] = su[j-1][i-1]+ su[j-1][i];
        }
        
    }
    printf("%d",su[num][num1]);
    
    return 0;
}
