/* check the another solution */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <ctype.h>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string result = "";

        for (int i=0; i<s.size(); i++){
            cout << "\ninitial int i = " << i;
            while(1){

                if(isdigit(s[i])){ // after that digit the next char is '['
                    int num = s[i] - '0';
                    
                    string subString = decodeString(s.substr(i+2));

                    for(int j=0; j<num; j++){
                        result += subString;
                    }

                    i += subString.size() + 1;

                    cout << "\nrecursive int i = " << i;

                }
                else if (s[i] == ']'){
                    break;
                }
                else{
                    cout << "\nstring s[i] = " << s[i];

                    result += s[i];
                }
                i++;
                cout << "\nnormal int i = " << i;
            }
        }

        cout << "\n\nresult = " << result;

        return result;
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
        cout << "\nInput: " << testCase << endl;
        string result = solution.decodeString(testCase);
        cout << "\nOutput: " << result << endl << endl;
    }

    return 0;
}
