/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//create a map maybe of digits to alphabets

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int soln_count = 0;

char alphabets(char digit,int idx){
    char ret[4];
    switch (digit)
    {
    case '2':
        strncpy(ret,"abc",3);
        return ret[idx];
        break;
    case '3':
        strncpy(ret,"def",3);
        return ret[idx];
        break;
    case '4':
        strncpy(ret,"ghi",3);
        return ret[idx];
        break;
    case '5':
        strncpy(ret,"jkl",3);
        return ret[idx];
        break;
    case '6':
        strncpy(ret,"mno",3);
        return ret[idx];
        break;
    case '7':
        strncpy(ret,"pqrs",4);
        return ret[idx];
        break;
    case '8':
        strncpy(ret,"tuv",3);
        return ret[idx];
        break;
    case '9':
        strncpy(ret,"wxyz",4);
        return ret[idx];
        break;
    default:
        break;
    }
    return 0;
}

void get_combo(char* digits,int n,char** ret,int idx,char* curr_soln){
    if(idx == n){
        curr_soln[n] = '\0';
        strncpy(ret[soln_count++],curr_soln,n+1);
        return;
    }
    int len = (digits[idx] != '7' && digits[idx] != '9') ? 3 : 4;
    for(int i = 0;i<len;i++){
        curr_soln[idx] = alphabets(digits[idx],i);
        get_combo(digits,n,ret,idx+1,curr_soln);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    //returnsize will actually be how man alphabets each digit can have
    int n = strlen(digits);
    int return_len = 1;
    for(int i = 0;i<n;i++){
        if(digits[i] == '7' || digits[i] == '9')
            return_len *= 4;
        else
            return_len *= 3;
    }

    char **ret = (char**)malloc(sizeof(char*)*return_len);
    for(int i =0;i<return_len;i++){
        ret[i] = (char*)malloc(sizeof(char)*(n + 1));
    }
    soln_count = 0;

    char curr_soln[n+1];
    get_combo(digits,n,ret,0,curr_soln);

    *returnSize = return_len;
    return ret;
}

int main(){
    int ret_size = 0;
    char** ret = letterCombinations("23",&ret_size);

    for(int i = 0;i<ret_size;i++){
        printf("%s\r\n",ret[i]);
    }

    printf("%d\r\n",ret_size);
}