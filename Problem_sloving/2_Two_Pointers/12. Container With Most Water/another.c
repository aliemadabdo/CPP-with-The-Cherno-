/*Hint 2
    Try to use two-pointers. 
    Set one pointer to the left and one to the right of the array. 
    Always move the pointer that points to the lower line.
*/

int min(int a, int b) {
    return (a > b) ? b : a;
}

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int maxarea = 0;
    
    while (left < right) {
        int area = (right - left) * min(height[left], height[right]);
        if (area > maxarea) {
            maxarea = area;
        }
        
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        } // "the easy yet difficult" 

        /*If you move the pointer pointing to the taller line, 
        you wouldn't increase the possible height of the container, 
        and thus you wouldn't find a larger area.
        
        By moving the pointer pointing to the shorter line,
        you might find a taller line, 
        increasing the potential height of the container and thus the area.*/
    }

    return maxarea;
}
