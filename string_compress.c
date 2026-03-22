//just make sure device print is in correct order and compensate for last char


#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "math.h"

int compress(char* chars, int charsSize) {
    char pattern[2000];
    int count = 1;
    int total_count = 0;
    int digit_count = 0;
    for(int i=1;i<charsSize;i++){
        if(chars[i] == chars[i-1]){
            count++;
        }
        else{
            pattern[total_count++] = chars[i-1];
            if(count > 1){
                digit_count = (log10(count) + 1);
                for(int a = 0;a<digit_count;a++) {
                    pattern[total_count++] = (char) ((count / ((int)pow(10,digit_count-1-a))) + 48);
                    count = (int) count%((int)pow(10,digit_count-1-a));
                } 
            }
            count = 1;
        }
    }
    pattern[total_count++] = chars[charsSize-1];
    if(count > 1){
        digit_count = (log10(count) + 1);
        for(int a = 0;a<digit_count;a++) {
            pattern[total_count++] = (char) ((count / ((int)pow(10,digit_count-1-a))) + 48);
            count = (int) count%((int)pow(10,digit_count-1-a));
        } 
    }
    memcpy(chars,pattern,total_count);
    return total_count;
}

int main(){
    char chars[] = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    int r = compress(chars,sizeof(chars)/sizeof(chars[0]));
    for(int a = 0;a<r;a++)
        printf("%c",chars[a]);
}