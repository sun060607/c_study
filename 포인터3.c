#include <stdio.h>

int main(){
    int arry[3] = {0,1,2};
    int *ptr;
    for(int i =0;i<3;i++){
        printf("%d\n",arry[i]);
    }
    ptr = &arry;
    *ptr = 10;
    *(ptr+1) = 20;
    *(ptr+2) = 300;
    printf("변경 이후 수들\n");
    for(int i =0;i<3;i++){
        printf("%d\n",arry[i]);
    }
    return 0;
}
