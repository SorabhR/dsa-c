//very nice problem do revisit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 10000

char* decodeString(char* s) {
    char* strStack[MAX];
    int numStack[MAX];
    int strTop = -1, numTop = -1;

    char* curr = (char*)calloc(MAX, sizeof(char));
    int k = 0;

    for (int i = 0; s[i]; i++) {
        if (isdigit(s[i])) {
            k = k * 10 + (s[i] - '0');
        }
        else if (s[i] == '[') {
            // push current string and k
            strStack[++strTop] = curr;
            numStack[++numTop] = k;

            // reset
            curr = (char*)calloc(MAX, sizeof(char));
            k = 0;
        }
        else if (s[i] == ']') {
            int repeat = numStack[numTop--];
            char* prev = strStack[strTop--];

            char* temp = (char*)calloc(MAX, sizeof(char));

            // repeat current string
            for (int j = 0; j < repeat; j++) {
                strcat(temp, curr);
            }

            strcat(prev, temp);

            free(curr);
            free(temp);

            curr = prev;
        }
        else {
            int len = strlen(curr);
            curr[len] = s[i];
            curr[len + 1] = '\0';
        }
    }

    return curr;
}