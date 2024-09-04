#include <iostream>
#include <queue>

using namespace std;

constexpr int windowTime = 3000;

class RecentCounter {
private:
    queue<int> requestsTime;

public:
    RecentCounter() { // constructor
        
    }
    
    int ping(int t) {
        requestsTime.push(t);

        while (requestsTime.back() - requestsTime.front() > windowTime){
            requestsTime.pop();
        }
        
        return requestsTime.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main() {
    RecentCounter* obj = new RecentCounter();
    
    // Test cases
    cout << obj->ping(1) << endl;    // Expected output: 1
    cout << obj->ping(100) << endl;  // Expected output: 2
    cout << obj->ping(3001) << endl; // Expected output: 3
    cout << obj->ping(3002) << endl; // Expected output: 3
    cout << obj->ping(7000) << endl; // Expected output: 1

    delete obj; // Clean up the allocated memory
    return 0;
}