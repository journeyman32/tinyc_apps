#include <stdio.h>

int main(){
    char sentence[] = "ASCII MAKES MY HEART BEAT FASTER\n";
    char *s;

    s = sentence;
    while(*s){
        if( *s>='A' && *s<='Z'){
            putchar(*s | 0x20);       
        } 
        else{
            putchar(*s);
        }
        s++;
    }
    s = sentence;
    while(*s){
        if( *s>='a' && *s<='z'){
            putchar(*s & 0xdf);
        }else{
            putchar(*s);
        }
        s++;
        
    }
    return(0);
}