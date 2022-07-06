#include <stdio.h>
int main(){
    int num1[100][100]={},num2,num3=1;
    scanf("%d",&num2);
    for(int i=0;i<num2;i++){
        for(int j=0;j<num2;j++){
            num1[i][j]=num3;
            num3++;
        }
    }
    for(int i=0;i<num2;i++){
        for(int j=0;j<num2;j++){
            printf("%d ",num1[i][j]);
        }
        printf("\n");
    }
    return 0;
}