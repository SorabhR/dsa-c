//imp note here is the middle element to be checked as well

#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "math.h"

bool isSubsequence(char* s, char* t) {
    int n = strlen(t);
    int ns = strlen(s);
    int i = 0;
    int j = n-1;
    int sub_start = 0;
    int sub_end = ns-1;

    if(ns>n)
        return false;
    if( n==0 || ns==0)
        return true;

    while(j>i){
        if(t[i] == s[sub_start])
            sub_start++;
        if(t[j] == s[sub_end])
            sub_end--;
        if(sub_end < sub_start)
            return true;        
        i++;
        j--;
    }
    if(i==j){
        if(t[i] == s[sub_start])
            sub_start++;
        else if(t[j] == s[sub_end])
            sub_end--;
        if(sub_end < sub_start)
            return true;   
    }
    return false;
    
}

int main(){
    char *s = "abc";
    char *t = "acbdc";
    printf("%d\r\n",isSubsequence(s,t));
}