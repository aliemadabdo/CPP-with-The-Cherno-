// we should have the set it self to pop from it 
// we don't need to know the next operation 
// we have to return when pop and non-return when addback
// we need to know if its ordered

#include <vector>
#include <string>

class SmallestInfiniteSet {
private:
    std::vector<std::string> function;
    std::vector<std::vector<int>> value;
    int index = 1;

public:
    SmallestInfiniteSet(std::vector<std::string> fn, std::vector<std::vector<int>> val) 
    : function(fn) , value(val) {}
    
    int popSmallest() {
        int smallest = value[0][0];
        value.pop_back();
        return smallest;
    }
    
    void addBack(int num) {
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */