#include "string.h"
#include "stdio.h"
#include "stdlib.h"

void break_string(char* s,const char* del){
    char *token; 
    token = strtok(s,del);

    while(token != NULL){
        printf("%s\n",token);
        token = strtok(0,del);
    }
}

int main(){
    char s[] = "Hey bro you are great";
    const char *del = " ";
    break_string(s,del);
    return 0;
}