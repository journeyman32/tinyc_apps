#include <stdio.h>

int main(){
    int ch;
    while ((ch=getchar()) != EOF){
        printf("%02x ", ch);
    }
    return 0;
}