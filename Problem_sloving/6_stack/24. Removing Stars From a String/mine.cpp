#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution { // a stack like solution with no need to pop and reverse the final result
public:
    string removeStars(string s) {
        vector<char> antiStar;

        for(char c : s){
            if((c == '*') && (!antiStar.empty()) ){ // remove a letter before a star
                antiStar.pop_back(); 
            }
            else{ // add a letter to the vector of chars
                antiStar.emplace_back(c);
            }
        }

        string result(antiStar.data(), antiStar.size());

        return result;
    }
};



void runTests() {

    Solution sol;

    // Test Case 1
    assert(sol.removeStars("ab*c*d") == "ad");

    // Test Case 2
    assert(sol.removeStars("abc***") == "");

    // Test Case 3
    assert(sol.removeStars("abcdefgh") == "abcdefgh");

    // Test Case 4
    assert(sol.removeStars("a*b*c*") == "");

    // Test Case 5
    assert(sol.removeStars("a*b*c*def***") == "");

    // Test Case 6
    assert(sol.removeStars("a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*") == "");

    // Test Case 7
    assert(sol.removeStars("") == "");

    // Test Case 8
    assert(sol.removeStars("a") == "a");

    // Test Case 9
    assert(sol.removeStars("a*") == "");

    // Test Case 10
    assert(sol.removeStars("abc***def") == "def");

    // Additional Custom Test Case for Performance
    std::string largeInput(100000, 'a');
    largeInput += std::string(100000, '*');
    assert(sol.removeStars(largeInput) == "");

    std::cout << "All test cases passed!" << std::endl;
}

int main() {
    runTests();
    return 0;
}