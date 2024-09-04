#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Your isSubsequence function
bool isSubsequence(char* s, char* t) {
    int index = 0;
    
    for(int i = 0; i < strlen(t); i++) {
        if(t[i] == s[index]) {
            index++;
        }
    }    

    return index == strlen(s);
}

int main() {
    // Test cases
    char* s1 = "abc";
    char* t1 = "ahbgdc";
    char* s2 = "axc";
    char* t2 = "ahbgdc";
    char* s3 = "";
    char* t3 = "ahbgdc";
    char* s4 = "abc";
    char* t4 = "";

    // Running the test cases
    printf("Test case 1: %s -> %s: %s\n", s1, t1, isSubsequence(s1, t1) ? "true" : "false");
    printf("Test case 2: %s -> %s: %s\n", s2, t2, isSubsequence(s2, t2) ? "true" : "false");
    printf("Test case 3: %s -> %s: %s\n", s3, t3, isSubsequence(s3, t3) ? "true" : "false");
    printf("Test case 4: %s -> %s: %s\n", s4, t4, isSubsequence(s4, t4) ? "true" : "false");

    return 0;
}
