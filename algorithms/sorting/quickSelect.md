Quickselect is an efficient algorithm used to find the k-th smallest (or largest) element in an unordered list, similar to the way Quicksort works but with partial sorting. It's widely used because of its average-case linear time complexity, \(O(n)\), although its worst-case time complexity is \(O(n^2)\).

### How Quickselect Works:
1. **Choose a Pivot:** Similar to Quicksort, Quickselect chooses a pivot element from the array.
2. **Partition the Array:** It partitions the array into two parts: elements smaller than the pivot on one side and elements larger than the pivot on the other side.
3. **Recursively Narrow Down:** Based on the position of the pivot after partitioning:
   - If the pivot is in the k-th position, it is the k-th smallest element, and the algorithm terminates.
   - If the pivot is before the k-th position, you search in the right part.
   - If the pivot is after the k-th position, you search in the left part.

This process continues until the pivot is found at the k-th position.

### C++ Code Example for Quickselect:
Here's an example implementation of the Quickselect algorithm to find the k-th smallest element:

```cpp

#include <iostream>
#include <vector>
#include <algorithm>  // For std::swap

int partition(std::vector<int>& nums, int left, int right) {
    int pivot = nums[right];  // Choose the rightmost element as pivot
    int i = left;
    for (int j = left; j < right; ++j) {
        if (nums[j] < pivot) {
            std::swap(nums[i], nums[j]);
            ++i;
        }
    }
    std::swap(nums[i], nums[right]);  // Move the pivot to its correct place
    return i;
}

int quickSelect(std::vector<int>& nums, int left, int right, int k) {
    if (left == right) {
        return nums[left];  // Only one element left
    }

    // Partition the array and get the pivot index
    int pivotIndex = partition(nums, left, right);

    // Check if the pivot is the k-th smallest element
    if (pivotIndex == k) {
        return nums[pivotIndex];
    } else if (pivotIndex > k) {
        // Search the left part
        return quickSelect(nums, left, pivotIndex - 1, k);
    } else {
        // Search the right part
        return quickSelect(nums, pivotIndex + 1, right, k);
    }
}

int findKthSmallest(std::vector<int>& nums, int k) {
    return quickSelect(nums, 0, nums.size() - 1, k - 1);  // k-1 because of zero-indexing
}

int main() {
    std::vector<int> nums = {7, 2, 1, 10, 9, 5, 6};
    int k = 3;
    std::cout << "The " << k << "-th smallest element is " << findKthSmallest(nums, k) << std::endl;
    return 0;
}
```

### Key Points:
- The `partition` function rearranges the array around a pivot.
- The `quickSelect` function recursively searches for the k-th smallest element by narrowing down the array.
- The average time complexity of Quickselect is \(O(n)\), making it faster than sorting-based approaches for selecting a single element.

This algorithm is particularly useful when you don't need a fully sorted array but only want to find a specific order statistic (like the median).