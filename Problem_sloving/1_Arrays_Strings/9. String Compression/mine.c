#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int compress(char* chars, int charsSize) {
    
    char* compressed = (char*)malloc(charsSize + 1);
    
    if (compressed == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    int count = 1, index = 0;

    for (int i = 0; i < charsSize-1; i++) {
        // Check if the current character is the same as the next character and not the last one
        if ((i < charsSize-1) && (chars[i] == chars[i + 1])) {
            count++; // Increment the count for consecutive identical characters
        } 
        else {
            // When the current character differs from the next or we reach the end of the string
            // Store the current character in the compressed string
            compressed[index] = chars[i];
            index++; // Move to the next position in the compressed string

            // If the count of consecutive characters is more than 1
            if (count > 1) {
                // Convert the count to a string and append it to the compressed string
                sprintf((compressed + index), "%d", count);
                // Update the index by the length of the count string
                index += (int)log10(count) + 1;
            }

            // Reset the count for the next sequence of characters
            count = 1;
        }
    }

    // last element handling
    compressed[index] = chars[charsSize-1];
    index++;

    if (count > 1) {
        // Convert the count to a string and append it to the compressed string
        sprintf((compressed + index), "%d", count);
        // Update the index by the length of the count string
        index += (int)log10(count) + 1;
    }
    // last element handling
    
    compressed[index] = '\0';
    strncpy(chars, compressed, index+1);

    return index;
}

int main(){
    char chars[] = "aabbccdeee";
    int charsSize = strlen(chars);

    printf("Original string: %s\n", chars);
    int newLength = compress(chars, charsSize);

    if (newLength != -1) {
        printf("Compressed string: %s\n", chars);
        printf("Compressed length: %d\n", newLength);
    }

    return 0;
}