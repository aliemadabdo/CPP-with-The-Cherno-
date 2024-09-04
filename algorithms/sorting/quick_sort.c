/*
 Algorithm Overview: Quick sort is a highly efficient sorting algorithm
 and is based on the divide-and-conquer principle. 
 
# Algorithm Steps overview
    1. Choose a Pivot: Select an element from the array as the pivot. 
       There are various strategies to choose a pivot, such as selecting the first element,
       the last element, the middle element, or a random element.
    2. Partitioning: Rearrange the elements in the array so that elements less than 
       the pivot are on the left side and elements greater than the pivot are on the right side.
    3. Recursively Apply: Recursively apply the above steps to the sub-arrays
       formed by dividing the array at the pivot.
*/

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to place the pivot element at its correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pivot element
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;  // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to implement QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partitioning index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}