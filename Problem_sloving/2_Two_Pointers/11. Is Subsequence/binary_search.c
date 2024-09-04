/* Binary search is an efficient algorithm for finding an item
   from a sorted list of items. It works by repeatedly dividing
   the search interval in half and comparing the target value to
   the middle element of the interval.    
*/
#include <stdio.h>

int binarySearch(int arr[], int arrSize, int target) {
    if (arrSize <= 0) {
        return -1;  // If array size is zero or negative, return -1
    }
    static int recursionLevel = 0;  // Static variable to track recursion depth
    int result = 0;

    int med = (arrSize - 1) / 2;  // Calculate the middle index

    recursionLevel++;  // Increase recursion depth
    printf("\nrecursion Level: %d", recursionLevel);

    if (arr[med] == target) {  // If the middle element is the target
        result = med;
        printf("\nrecursion Level: %d", recursionLevel);
        printf("\nresult = %d ", med);

        recursionLevel--;  // Decrease recursion depth
        return result;
    } else if (arr[med] > target) {  // If target is less, search in the left half
        result = binarySearch(arr, med, target);

        printf("\nrecursion Level: %d", recursionLevel);
        printf("\nresult - %d ", result);

        recursionLevel--;  // Decrease recursion depth

        return result;
    } else {  // If target is greater, search in the right half
        result = binarySearch(arr + med + 1, arrSize - med - 1, target);

        printf("\nrecursion Level: %d", recursionLevel);
        printf("\nresult: + %d ", result);

        if (result == -1) {
            return -1;  // Target not found in the right half
        }

        recursionLevel--;  // Decrease recursion depth

        return result + med + 1;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    int result = binarySearch(arr, arrSize, target);
    printf("\nFinal result: %d\n", result);

    return 0;
}
