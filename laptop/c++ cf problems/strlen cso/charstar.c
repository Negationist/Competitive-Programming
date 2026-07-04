#include <stdio.h>
#include <stdlib.h>

size_t mystrlen(const char *s){
    size_t len = 0;
    while(1){
        if(*(s+len)=='\0'){
            break;
        }
        ++len;
    }
    return len;
}

char *simple_split(char *s, char delim){
    if(s==NULL){
        return NULL;
    }
    int inc = 0;
    while(*(s+inc)!='\0'){
        if(*(s+inc)==delim){
            *(s+inc) = '\0';
            return s+inc+1;
        }
        ++inc;
    }
    return NULL;
}

int main()
{

    return 0;
}
