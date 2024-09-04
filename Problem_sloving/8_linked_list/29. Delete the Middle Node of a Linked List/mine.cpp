#include <iostream>
#include <vector>
#include <stdbool.h>

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
    ListNode* deleteMiddle(ListNode* head) { 
        // Fast and slow pointers are used to find the middle of the list.
        ListNode* fast = head;
        ListNode* slow = head;

        if (!head || !head->next) return nullptr; // Edge case: empty list or single node list

        while (1)
        {   

            fast = fast->next->next;
            if(fast && fast->next){
                slow = slow->next;
            } else {
                break;
            }

        }

        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete; // to preivent memory leaks

        return head; 
        
    }
};

// Function to print the linked list
void printList(ListNode*);

// Function to create a linked list from an array
ListNode* createList(const vector<int>& );

int main() {
    Solution solution;

    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    std::vector<int> values = {1, 2, 3, 4, 5, 6, 7,8,9};
    ListNode* head = createList(values);

    std::cout << "Original List: ";
    printList(head);

    // Delete the middle node
    head = solution.deleteMiddle(head);

    std::cout << "\nModified List: ";
    printList(head);

    // Clean up the list
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}


void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" ;
}

 
ListNode* createList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}