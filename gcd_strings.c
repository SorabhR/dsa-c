#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"

int gcd_len(int a,int b){
    if(b==0) return a;
    return gcd_len(b,a%b);
}

char* gcdOfStrings(char* str1, char* str2) {
    uint16_t len1 = strlen(str1);
    uint16_t len2 = strlen(str2);
    uint16_t lenT = gcd_len(len1,len2);
    char* t = (char*)malloc(lenT+1);
    char* r = t;

    if(lenT == 1){
        int count = 0;
        int countLlater = 0;
        int bigger = 0;
        if(len1>len2){
            count = len2;
            countLlater = len1;
            bigger = 1;
        }
        else{
            count = len1;
            countLlater = len2;
            bigger=0;
        }
        int i = 1;
        for (;i<count;i++){
            if((str1[0] != str1[i]) || ((str1[0] != str2[i]))){
                *t = '\0';
                return r;
            }
        }
        for (;i<countLlater;i++){
            if(bigger){
                if(str1[0] != str1[i]){
                    *t = '\0';
                    return r;
                }
            }
            else{
                if(str2[0] != str2[i]){
                    *t = '\0';
                    return r;
                }
            }
        }
        *t++ = str1[0];
        *t = '\0';
        return r;        
    }else{
        strncpy(t,str1,lenT);
        *(t+lenT) = '\0';
        while(strncmp(str1,t,lenT) == 0){
            str1+=lenT;
            len1-=lenT;
        }
        if(len1 != 0){
            *r = '\0';
            return r;
        }

        while(strncmp(str2,t,lenT) == 0){
            str2+=lenT;
            len2-=lenT;
        }
        if(len2 != 0){
            *r = '\0';
            return r;
        }

    }
    return r;
}

int main(){
    // printf("%d\r\n",gcd_len(6,3));
    char* s1 = "A";
    char* s2 = "AA";
    char* t = gcdOfStrings(s1,s2);
    printf("%s\r\n",t);
}