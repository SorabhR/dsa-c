#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

bool isVowel(char s){
    return ((s=='a') || (s=='e')|| (s=='i') || (s=='o') || (s=='u') || (s=='A') || (s=='E') || (s=='I') || (s=='O') || (s=='U'));
}

char* reverseVowels(char* s) {
    int iplen = strlen(s);
    int indices[iplen];
    int noVowels = 0;

    for(int i=0;i<iplen;i++){
        if(isVowel(s[i])){
            indices[noVowels++] = i;
        }
    }


    for(int i=0;i<noVowels/2;i++){
        char temp = s[indices[i]];
        s[indices[i]] = s[indices[noVowels - i -1]];
        s[indices[noVowels - i -1]] = temp;
    }

    return s;
}

int main(){
    char s[] = "leetcode";
    char *r = reverseVowels(s);
    printf("%s\r\n",r);
}