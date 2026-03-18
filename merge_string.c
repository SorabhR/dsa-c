#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "stdlib.h"

char * mergeAlternately(char * word1, char * word2){
    uint8_t w1 = strlen(word1);
    uint8_t w2 = strlen(word2);
    char *merged=(char*)malloc(strlen(word1)+strlen(word2)+1);
    char* r = merged;
    uint8_t i = 0;

    while(w1 && w2){
        *merged++ = *word1++;
        *merged++ = *word2++;
        w1--;
        w2--;
    }

    if(w1){
        memcpy(merged,word1,w1);
        merged = merged+w1; 
    }
    else{
        memcpy(merged,word2,w2);
        merged = merged+w2;
    } 
    *merged = '\0';
    return r;
}

int main(){
    char* w1 = "ab";
    char* w2 = "pqrs";

    char* op = mergeAlternately(w1,w2);
    printf("%s\r\n",op);
    return 0;
}