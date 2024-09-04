#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <ctype.h>

using namespace std;

class Solution {
public:
    string decodeString(const string& s) { // #NOTE: no need for recursion
        stack<int> counts;     // #NOTE: two stacks approach 
        stack<string> results; // #NOTE: stack of strings
        string currentString;
        int currentCount = 0;

        for (char c : s) {
            if (isdigit(c)) {
                // #NOTE: Build the number (could be more than one digit)
                currentCount = currentCount * 10 + (c - '0');
            } else if (c == '[') {
                // Push the current string and count onto stacks
                counts.push(currentCount);
                results.push(currentString);
                // Reset current string and count
                currentString.clear();
                currentCount = 0;
            } else if (c == ']') {
                // Pop the count and the string, then repeat and append
                string temp = currentString;
                int repeatCount = counts.top();
                counts.pop();
                string prevString = results.top();
                results.pop();
                for (int i = 0; i < repeatCount; ++i) {
                    prevString += temp;
                }
                currentString = prevString;
            } else {
                // Append the current character to the current string
                currentString += c;
            }
        }

        return currentString;
    }
};

int main() {
    Solution solution;

    // Test cases
    vector<string> testCases = {
        "3[a]2[bc]",     // Expected output: "aaabcbc"
        "3[a2[c]]",      // Expected output: "accaccacc"
        "2[abc]3[cd]ef", // Expected output: "abcabccdcdcdef"
        "10[a]",         // Expected output: "aaaaaaaaaa"
        "2[abc]3[cd]ef2[gh]" // Expected output: "abcabccdcdcdefghgh"
    };

    for (const string& testCase : testCases) {
        cout << "Input: " << testCase << endl;
        string result = solution.decodeString(testCase);
        cout << "Output: " << result << endl << endl;
    }

    return 0;
}
