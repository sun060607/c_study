#include <stdio.h>
struct score{
    int mic;
    int lin;
    int pro;
    char name[20];
};
int main(){
    struct score s1[2]={0};
    for(int i=0;i<2;i++){
        scanf("%s",s1[i].name);
        scanf("%d",&s1[i].mic);
    }
    printf("%5d %5d %5d\n",s1.mic,s1.lin,s1.pro);
    return 0;
}
