#include <stdio.h>
#include <stdbool.h>

// The given function to check if we can place flowers
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int availablePlaces = 0, validPlaces = 0;

    if (flowerbedSize == 1){
        return !(flowerbed[0] & n);
    }


    if (flowerbedSize >= 2){
        if(flowerbed[0] == 0 && flowerbed[1] == 0){
            validPlaces++; 
        }

        // printf("Valid Places: %d\t", validPlaces);

        if(flowerbed[flowerbedSize-1] == 0 && flowerbed[flowerbedSize-2] == 0 && flowerbedSize > 2){
            validPlaces++; 
        }

        // printf("Valid Places: %d\t", validPlaces);

    }

    if (validPlaces >= n) {
            return true;  // More optimized solution than mine, as it does not wait to count all valid places, 
                          // it just check if the flower bed satisfy the required n flowers to plant.
    }

    for (int i = 1; i < flowerbedSize - 1; i++){
        if (flowerbed[i] == 0){
            availablePlaces++ ;
            if (availablePlaces != 1){
                validPlaces += availablePlaces % 2;
            }
        }
        else{
            availablePlaces = 0;
        }
 
        if (validPlaces >= n) {
            return true;  // More optimized solution than mine, as it does not wait to count all valid places, 
                          // it just check if the flower bed satisfy the required n flowers to plant.
        }
    }

    printf("Valid Places: %d\t", validPlaces);

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
