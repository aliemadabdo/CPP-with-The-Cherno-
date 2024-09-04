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



class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head; // Edge case: empty list or single node list
        
        ListNode* postNode = head->next;
        ListNode* preNode = nullptr;

        while(postNode){
            head->next = preNode;
            preNode = head;
            head = postNode;
            postNode = postNode->next;
        }

        head->next = preNode;

        return head;
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

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Solution solution;

    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createList(values);

    cout << "Original List: ";
    printList(head);

    // Reverse the list
    head = solution.reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    // Clean up the list
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
