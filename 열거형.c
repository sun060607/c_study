#include <stdio.h>
typedef union{
    unsigned int val;
    struct{
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;//투명도
    };
}color;

int main(){
    color sample;
    sample.val = 0xffffffff;
    sample.b = 0x00;
    printf("%x\n",sample.val);
    return 0;
}
