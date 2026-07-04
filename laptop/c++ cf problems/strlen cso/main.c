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
    //printf("here\n");
    int inc = 0;
    while(*(s+inc)!='\0'){
        //printf("%d",inc);
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
    char *s = strdup("can all aardvarks quaff?");
    char *bit = simple_split(s, 'a');
    puts(s);
    puts(bit);
    free(s);
    return 0;
}
