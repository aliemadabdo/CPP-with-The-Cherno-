// Author: Amr Elmaghraby

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        
    }
};

std::ostream & operator << (std::ostream&os,vector<int>&vec){
    os<<"[";
    for(size_t i=0;i<vec.size();++i){
        os<<vec[i];
        if (i!=(vec.size()-1))
        {
            os<<",";
        }
    }
    os<<"]"<<std::endl;
    return os;
}

int main()
{
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    Solution sol;
    std::cout << nums;
    std::cout << sol.findKthLargest(nums, 4);
    return 0;
}