#include <string.h>
#include <stdlib.h>

char* gcdOfStrings(char* str1, char* str2) {

    /* VARIBALES */
    short str1_len = strlen(str1);
    short str2_len = strlen(str2);
    short gcd_len = 0;

   
    /* Get GCD */
    for(short i = 1; (i <= str2_len) && (i <= str1_len) ; i++){
        if( (str1_len % i == 0) && (str2_len % i == 0) ){
            gcd_len = i;
        }
    }

    /* Store GCD String*/
    char* gcd_str = (char*)malloc((gcd_len + 1) * sizeof(char));
    strncpy(gcd_str, str1, gcd_len);
    gcd_str[gcd_len] = '\0'; //NOTE

    /* Validate GCD String */
    short str1_div = str1_len / gcd_len;
    short str2_div = str2_len / gcd_len;

    // Check if the GCD string can construct both strings
    for (short i = 0; i < str1_len; i += gcd_len) {
        if (strncmp(gcd_str, str1 + i, gcd_len) != 0) {
            free(gcd_str);
            return "";
        }
    }

    for (short i = 0; i < str2_len; i += gcd_len) {
        if (strncmp(gcd_str, str2 + i, gcd_len) != 0) {
            free(gcd_str);
            return "";
        }
    }
        
    return gcd_str;
}

int main(){
    char str1[] = "AAA";
    char str2[] = "AAA";

    char* gcd = gcdOfStrings(str1, str2);

    printf("\ngcd len = %d", strlen(gcd));

    for (int i = 0; i < strlen(gcd); i++){
        printf("\n %c", gcd[i]);
    }

    return 0;
}
