#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        vector<vector<int>> result; 
        unordered_map<int, int> diffMap;
        
        for(int i=0; i<nums1.size(); i++){
            diffMap[nums1[i]] = 1;
        }

        for(int i=0; i<nums2.size(); i++){

            try{
                if( (diffMap.at(nums2[i]) == 1) || (diffMap.at(nums2[i]) == 0) ){
                    diffMap[nums2[i]] = 0;
                }
            } catch (const std::out_of_range& e) {
                diffMap[nums2[i]] = 2;
            }
        }

        result.push_back(vector<int>()); // add first row
        result.push_back(vector<int>()); // add second row

        for(auto i=diffMap.begin(); i != diffMap.end(); i++){
            if(i->second == 1){
                result[0].push_back(i->first);
            }
            else if(i->second == 2){
                result[1].push_back(i->first);
            }
        }

        return result;
        
    }
};

int main() {
    Solution solution; // [1, 2, 3, 6, 7]
    vector<int> nums1 = {1, 2, 3, 3, 4, 5, 6, 7, 7, 11, 1000, 1000}; // [4, 5, 11, 1000]
    vector<int> nums2 = {6, 7, 8, 9, 1, 2, 2, 3, 3, 3}; // [8, 9]

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