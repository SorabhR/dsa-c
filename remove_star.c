//thodasa overkill tha
//needed nahi tha for stack actually could have done the operation in place for string more optimal


#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct Node{
    char ele;
    struct Node* next;
}Node;

char* removeStars(char* s) {
    int n = strlen(s);
    Node *head = NULL;
    int final_len = 0;
    for(int i=0;i<n;i++){
        if(s[i] != '*'){
            Node *temp = (Node*)malloc(sizeof(Node));
            temp->ele = s[i];
            temp->next = head;
            head = temp;
            final_len++;
        }
        else{
            if(head != NULL){
                Node *temp = head;
                head = head->next;
                final_len--;
                free(temp);
            }
        }
    }
    char* result = (char*)malloc(sizeof(char)*(final_len+1));
    Node* curr = head;
    for(int i = final_len-1;i>=0;i--){
        result[i] = curr->ele;
        curr = curr->next;
    }
    result[final_len] = '\0';
    return result;
}

int main(){
    char s[] = "leet**cod*e";
    printf("%s\r\n",removeStars(s));
}