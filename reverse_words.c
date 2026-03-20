//here another easy approach would be to have another array
//check og array till you reach space from space to end copy word to result array
//repeat till you reach start of code

#include "string.h"
#include "stdio.h"
#include "stdlib.h"

int countSpaces(char *str)
{
    int count = 0;

    while (*str != '\0')
    {
        if (*str == ' ')
            count++;

        str++;  // move to next character
    }

    return count;
}

char* reverseWords(char* s){
    const char* del = " ";
    int count = strlen(s); //give count of total char in string
    char *token; 

    int countsp = countSpaces(s);
    char **data = malloc((countsp+1)*sizeof(char*));
    
    token = strtok(s,del);
    int i = 0;
    
    while(token != NULL){
        data[i] = token;
        i++;
        token = strtok(0,del);
    }

    char* r = (char*) malloc(sizeof(char)*(count+1));
    char* t = r;
    for(int a=i-1;a>=0;a--){
        strncpy(r,data[a],strlen(data[a]));
        r+=strlen(data[a]);
        if(a!=0)
            *r++ = ' ';
        else
            *r++ = '\0';    
    }
    free(data);
    return t;
}

int main(){
    char s[] = "the sky is blue";
    char* r = reverseWords(s);
    printf("%s\r\n",r);
    return 0;
}