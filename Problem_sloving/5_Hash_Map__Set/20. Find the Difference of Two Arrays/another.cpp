#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<int> uniqueToNums1;
        vector<int> uniqueToNums2;

        // Find elements unique to nums1
        for (int num : nums1) {
            if (set2.find(num) == set2.end()) {  // Not in nums2
                uniqueToNums1.push_back(num);
            }
        }

        // Find elements unique to nums2
        for (int num : nums2) {
            if (set1.find(num) == set1.end()) {  // Not in nums1
                uniqueToNums2.push_back(num);
            }
        }

        return {uniqueToNums1, uniqueToNums2};
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {3, 4, 5, 6};

    vector<vector<int>> result = solution.findDifference(nums1, nums2);

    cout << "Elements unique to nums1: ";
    for (int num : result[0]) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Elements unique to nums2: ";
    for (int num : result[1]) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
