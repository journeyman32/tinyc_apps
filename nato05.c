//
// Created by Bryan on 7/23/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char isterm(char *term) {
    const char *nato[] = {
            "Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot",
            "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima",
            "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo",
            "Sierra", "Tango", "Uniform", "Victor", "Whiskey",
            "Xray", "Yankee", "Zulu"
    };

    int x;
    const char *n;
    char *t;

    for (x = 0; x < 26; x++) {
        n = nato[x];
        t = term;
        while (*n != '\0') {
            if ((*n | 0x20) != (*t | 0x20))
                break;
            n++;
            t++;
        }
        if (*n == '\0')
            return (*nato[x]);
    }
    return ('\0');
}

int main(int argc, char *argv[]){
    FILE *n;
    char phrase[64];
    char *match,ch,offset;

    if(argc<2){
        fprintf(stderr,"Please supply a text file argument\n");
        exit(1);
    }

    n = fopen(argv[1],"r");
    if(n == NULL)
    {
        fprintf(stderr,"Unable to open '%s'\n",argv[1]);
        exit(1);
    }

    offset = 0;
    while((ch = fgetc(n)) != EOF)
    {
        if(isalpha(ch)){
            phrase[offset] = ch;
            offset++;
            if(offset >=64){
                fprintf(stderr,"Buffer overflow\n");
                return(1);
            }
        }
        else{
            if(offset>0){
                phrase[offset] = '\0';
                putchar(isterm(phrase));
                offset=0;
            }
        }
    }
    putchar('\n');
    fclose(n);

    return(0);
}