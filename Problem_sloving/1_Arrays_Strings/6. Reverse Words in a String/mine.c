#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_WORD_SIZE 50

bool isAlphanumeric(char c) {
    // Check if the character is a letter (upper-case or lower-case) or a digit
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
}

char* getWord(char* str, int* pos){

    char* result = (char*)malloc( MAX_WORD_SIZE * sizeof(char) );
    int i = 0;

    while((str[*pos] != ' ') && (*pos < strlen(str))){
        result[i] = str[*pos];
        i++;
        (*pos)++;
    }

    result[i] = '\0';

    return result;
}

char* reverseWords(char* s) {

    int length = strlen(s);
    char* revStr = (char*)malloc( (length + 1) * sizeof(char) );
    char* word;
    int redundantSpaces = 0, wordPos = 0, resultLen;


    // Count redundant spaces to get the new string size
    for(int i=0;i<length;i++){
        if((s[i] == ' ') && ( (i == 0) || (i == length-1) || (s[i+1] == ' '))){
            redundantSpaces++;
        }
    }

    // Edge case: more than one space at the string begging
    if((s[0] == ' ') && (s[1] == ' ')){
        redundantSpaces++;
    }

    resultLen = length - redundantSpaces;

    for (int i=0; i<length; i++){
        if( isAlphanumeric(s[i]) ){ //condition may fail due to null char
            
            // Parse string words
            word = getWord(s, &i);

            // The new position of the word
            wordPos += strlen(word) + 1;
            
            // Write the word in reversed place
            for(int j=0; j<strlen(word); j++){
                revStr[resultLen - wordPos + j + 1] = word[j];
            }

            // Add space between words 
            if(resultLen > wordPos){
                revStr[resultLen - wordPos ] = ' '; // add space between words or null char at the end of the reversed string
            }

            // Free the returned allocated space
            free(word);
        }
    }
    
    // Null character for string termination 
    revStr[resultLen] = '\0';

    return revStr;
}

int main() {
    char str[] = "helloooo,   everyone... aim ali from alex!!! ";
    printf("Original: xxx%sxxx\n", str);

    char* reversed = reverseWords(str);
    printf("Reversed: xxx%sxxx\n", reversed);

    // Free the allocated memory for the reversed string
    free(reversed);
    
    return 0;
}