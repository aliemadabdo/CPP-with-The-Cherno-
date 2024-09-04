/*ANOTHER SOLUTION WITH Euclidean Algorithm from chatGPT*/

#include <string.h>
#include <stdlib.h>

// Function to calculate the GCD of two integers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

char* gcdOfStrings(char* str1, char* str2) {
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);
    int gcd_len = gcd(str1_len, str2_len);

    // Create a buffer to store the GCD string
    char* gcd_str = (char*)malloc((gcd_len + 1) * sizeof(char));
    strncpy(gcd_str, str1, gcd_len);
    gcd_str[gcd_len] = '\0';

    // Check if the GCD string can construct both strings
    for (int i = 0; i < str1_len; i += gcd_len) {
        if (strncmp(gcd_str, str1 + i, gcd_len) != 0) {
            free(gcd_str);
            return "";
        }
    }

    for (int i = 0; i < str2_len; i += gcd_len) {
        if (strncmp(gcd_str, str2 + i, gcd_len) != 0) {
            free(gcd_str);
            return "";
        }
    }

    return gcd_str;
}

int main() {
    char str1[] = "ALIALIALIALI";
    char str2[] = "ALIALIALI";

    char* gcd = gcdOfStrings(str1, str2);

    if (strlen(gcd) > 0) {
        printf("GCD of strings: %s\n", gcd);
    } else {
        printf("No common GCD string found.\n");
    }

    free(gcd);
    return 0;
}
