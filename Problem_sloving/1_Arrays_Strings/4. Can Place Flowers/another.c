#include <stdio.h>
#include <stdbool.h>

// The given function to check if we can place flowers
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int count = 0;
    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i] == 0 &&
            (i == 0 || flowerbed[i - 1] == 0) &&
            (i == flowerbedSize - 1 || flowerbed[i + 1] == 0)) {
            flowerbed[i] = 1;
            count++;
        }
        if (count >= n) {
            return true;  // More optimized solution than mine, as it does not wait to count all valid places, 
                          // it just check if the flower bed satisfy the required n flowers to plant.
        }
    }
    return false;
}


// Main function to test the canPlaceFlowers function
int main() {
    int flowerbed1[] = {1, 0, 0, 0, 1};
    int flowerbedSize1 = 5;
    int n1 = 1; // PASS

    int flowerbed2[] = {1, 0, 0, 0, 1};
    int flowerbedSize2 = 5;
    int n2 = 2; // FAIL

    int flowerbed3[] = {0, 0, 1, 0, 0};
    int flowerbedSize3 = 5;
    int n3 = 2; // PASS

    int flowerbed4[] = {0, 0, 0, 0, 0};
    int flowerbedSize4 = 5;
    int n4 = 3; // PASS

    int flowerbed5[] = {1, 0, 1, 0, 1};
    int flowerbedSize5 = 5;
    int n5 = 1; // FAIL

    printf("Test Case 1: %s\n", canPlaceFlowers(flowerbed1, flowerbedSize1, n1) ? "Pass" : "Fail");
    printf("Test Case 2: %s\n", canPlaceFlowers(flowerbed2, flowerbedSize2, n2) ? "Pass" : "Fail");
    printf("Test Case 3: %s\n", canPlaceFlowers(flowerbed3, flowerbedSize3, n3) ? "Pass" : "Fail");
    printf("Test Case 4: %s\n", canPlaceFlowers(flowerbed4, flowerbedSize4, n4) ? "Pass" : "Fail");
    printf("Test Case 5: %s\n", canPlaceFlowers(flowerbed5, flowerbedSize5, n5) ? "Pass" : "Fail");

    return 0;
}
