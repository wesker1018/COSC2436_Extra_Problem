#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Clone each node and insert it next to the original node
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // Step 2: Assign random pointers for the copied nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate the two lists
        curr = head;
        Node* newHead = head->next;
        Node* copyCurr = newHead;

        while (curr) {
            curr->next = curr->next->next;
            if (copyCurr->next) {
                copyCurr->next = copyCurr->next->next;
            }
            curr = curr->next;
            copyCurr = copyCurr->next;
        }

        return newHead;
    }
};

// Helper function to print the list (for testing)
void printList(Node* head) {
    Node* curr = head;
    int index = 0;
    while (curr) {
        cout << "Node " << index << ": val=" << curr->val;
        if (curr->random) cout << ", random->val=" << curr->random->val;
        else cout << ", random=null";
        cout << endl;
        curr = curr->next;
        index++;
    }
}

int main() {
    // Example: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]

    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);

    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5;
    n1->random = nullptr;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    cout << "Original List:" << endl;
    printList(n1);

    Solution sol;
    Node* copied = sol.copyRandomList(n1);

    cout << "\nCopied List:" << endl;
    printList(copied);

    return 0;
}
