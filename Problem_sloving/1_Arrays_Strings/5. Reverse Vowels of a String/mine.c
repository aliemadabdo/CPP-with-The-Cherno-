#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define IS_VOWEL_FWD (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
#define IS_VOWEL_BCK (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' || s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U')

char* reverseVowels(char* s) {

    char* reversedVwl = (char*)malloc((strlen(s)+1) * sizeof(char));
    // Check allocation success
    if (reversedVwl == NULL){
        return NULL;
    } 
   
    int length = strlen(s);
    int i = 0, j = length - 1;

    strcpy(reversedVwl, s);

    while(i < j){

        if (IS_VOWEL_FWD && IS_VOWEL_BCK){
            reversedVwl[i] = s[j];
            reversedVwl[j] = s[i];

            j--;
            i++;
        }
        else{
            j -= !IS_VOWEL_BCK;
            i += !IS_VOWEL_FWD;
        }
    }
    
    return reversedVwl;
}


int main() {
    char* testCases[] = {
        "education",
        "hello",
        "leetcode",
        "aEIoU",
        "abcdef",
        "AEIOU",
        "rhythm",
        "",
        "a",
        "sky",
        "beautiful",
        NULL // Sentinel value to mark the end of the array
    };

    for (int i = 0; testCases[i] != NULL; i++) {
        printf("TEST CASE NOT NULL\n");

        char* result = reverseVowels(testCases[i]);
        if (result != NULL) {
            printf("Original string: %s\n", testCases[i]);
            printf("Reversed vowels: %s\n", result);
            free(result); // Don't forget to free the allocated memory
        } else {
            printf("Memory allocation failed for string: %s\n", testCases[i]);
        }
        printf("\n"); // Add a newline for better readability between test cases
    }

    return 0;
}