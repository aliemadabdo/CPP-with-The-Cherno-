#include <iostream>
#include <queue>
#include <string>

using namespace std;

string predictPartyVictory(string s) {
    // Queues to store the indices of votes for Radiant and Dire
    queue<int> radiantQueue, direQueue;
    
    // Initialize the queues with the indices of votes
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'R') {
            radiantQueue.push(i); // Add index to Radiant queue
        } else {
            direQueue.push(i); // Add index to Dire queue
        }
    }
    
    // Process the voting until one of the queues is empty
    while (!radiantQueue.empty() && !direQueue.empty()) {
        // Get the indices of the current votes at the front of the queues
        int radiantIndex = radiantQueue.front();
        int direIndex = direQueue.front();
        radiantQueue.pop(); // Remove the current Radiant vote
        direQueue.pop();   // Remove the current Dire vote
        
        // Compare the indices to decide which vote survives
        if (radiantIndex < direIndex) {
            // Radiant vote survives, push its index back with an added length
            radiantQueue.push(radiantIndex + s.size());
        } else {
            // Dire vote survives, push its index back with an added length
            direQueue.push(direIndex + s.size());
        }
    }
    
    // Determine the winner based on which queue is not empty
    return radiantQueue.empty() ? "Dire" : "Radiant";
}

int main() {
    string votes;
    cout << "Enter the vote string: ";
    cin >> votes; // Read the vote string from input
    cout << "The winner is: " << predictPartyVictory(votes) << endl; // Output the result
    return 0;
}
