/* Bubble sort is a simple sorting algorithm that repeatedly steps through the list,
 compares adjacent elements, and swaps them if they are in the wrong order.*/

int* bubbleSort(int arr[], int size){
    int temp;
    
    for(int i=size-1; i>0; i--){
        for(int j=0; j<i; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    return arr;
}