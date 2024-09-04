#include <stdio.h>

int min(int a, int b){
    return (a>b)?b:a;
}

int maxArea(int* height, int heightSize) {
    
    int leftHeight = 0 , rightHeight = 0, area = 0, maxarea = 0;
    
    for(int i=0; i<heightSize; i++){

        if(height[i] > leftHeight){
            leftHeight = height[i];

            for(int j=heightSize-1; j>i; j--){
                if(height[j] > rightHeight){
                    rightHeight = height[j];

                    area = (j-i) * min(leftHeight, rightHeight);
                    if(area >= maxarea){
                        maxarea = area;
                    }
                }
            }
            rightHeight = 0;
        }
    }

    return maxarea;
}


int main() {
    // Test case 1
    int height1[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int heightSize1 = sizeof(height1) / sizeof(height1[0]);
    printf("Max Area for Test Case 1: %d\n", maxArea(height1, heightSize1));

    // Test case 2
    int height2[] = {1, 1};
    int heightSize2 = sizeof(height2) / sizeof(height2[0]);
    printf("Max Area for Test Case 2: %d\n", maxArea(height2, heightSize2));

    // Test case 3
    int height3[] = {4, 3, 2, 1, 4};
    int heightSize3 = sizeof(height3) / sizeof(height3[0]);
    printf("Max Area for Test Case 3: %d\n", maxArea(height3, heightSize3));

    // Test case 4
    int height4[] = {1, 2, 1};
    int heightSize4 = sizeof(height4) / sizeof(height4[0]);
    printf("Max Area for Test Case 4: %d\n", maxArea(height4, heightSize4));

    return 0;
}