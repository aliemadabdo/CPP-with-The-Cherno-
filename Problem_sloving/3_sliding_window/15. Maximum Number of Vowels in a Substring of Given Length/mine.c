#include <stdbool.h> // For the bool type

bool isVowel(char c) {
    // Check if the character is a lowercase vowel
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int maxVowels(char* s, int k) {
    int sum = 0, len = strlen(s);

    // initialize the window
    for(int i = 0; i<k; i++){
        if(isVowel(s[i])){
            sum++;
        }
    }

    int maxSum = sum;

    // Slide the window across the array
    for(int i = k; i < len; i++) {
        if(isVowel(s[i])){
            sum++;
        }
        if(isVowel(s[i-k])){
            sum--;
        }
        if(sum > maxSum) {
            maxSum = sum;
        }
    }

    return maxSum;
}