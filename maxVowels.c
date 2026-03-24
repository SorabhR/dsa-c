#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

bool isVowel(char s){
    return ((s=='a') || (s=='e')|| (s=='i') || (s=='o') || (s=='u'));
}


int maxVowels(char* s, int k) {
    int i = 0;
    int n = strlen(s);
    int count_vowel = 0;
    int max = 0;
    for(;i<k;i++){
        if(isVowel(s[i]))
            count_vowel++;
    }
    if(count_vowel == k)
        return k;
    max = count_vowel;
    while(i<n){
        if(isVowel(s[i-k]))
            count_vowel--;
        if(isVowel(s[i]))
            count_vowel++;    
        if(count_vowel == k)
            return k;
        if(count_vowel > max)
            max = count_vowel;    
        i++;
    }
    return max;
}

int main(){
    char *s = "leetcode";
    int k = 3;
    printf("%d\r\n",maxVowels(s,k));
}