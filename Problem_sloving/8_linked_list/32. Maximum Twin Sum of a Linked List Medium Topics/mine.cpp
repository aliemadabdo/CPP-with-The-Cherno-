#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}

ListNode* getMiddle(ListNode* head) { 
    // Fast and slow pointers are used to find the middle of the list.
    ListNode* mid = head;

    while (true)
    {   
        // cout << "\nmid value: " << mid;  
        head = head->next->next;
        if(!head) break;
        mid = mid->next;
        // cout << "\nmid value: " << mid;  

    }
        // cout << "\n return mid value: " << mid;  

    return mid; 
}

void halfreverseList(ListNode* head) { // the main idea as we get the list twised like a U-shape
    ListNode* mid = head;

    if (!head->next->next) return; // Edge case: single twin
    
    head = head->next;

    ListNode* postNode = head->next;
    ListNode* preNode = nullptr;

    while(postNode){
        head->next = preNode;
        preNode = head;
        head = postNode;
        postNode = postNode->next;
    }

    head->next = preNode;
    mid->next = head;
}
 
class Solution {
public:
    int pairSum(ListNode* head) { // How can "reversing" a part of the linked list help find the answer?
        
        int sum = 0, maxSum = 0;

        ListNode* secondHalfHead = getMiddle(head);

        halfreverseList((secondHalfHead));
        // printList(head);

        secondHalfHead = secondHalfHead->next;

        while (secondHalfHead)
        {
            sum = secondHalfHead->val + head->val;
            if(sum>maxSum){
                maxSum = sum;
            }
            secondHalfHead = secondHalfHead->next;
            head = head->next;

        }

        return maxSum;
        
    }
};

// Function to create a linked list from a vector of values
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Function to clean up the linked list
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}



int main() {
    Solution solution;

    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    vector<int> values = {1, 2, 3, 4, 5, 6};
    ListNode* head = createList(values);

    // Find the maximum twin sum
    int maxTwinSum = solution.pairSum(head);

    // Print the result
    cout << "Maximum Twin Sum: " << maxTwinSum << endl;

    // Clean up the linked list
    deleteList(head);

    return 0;
}
