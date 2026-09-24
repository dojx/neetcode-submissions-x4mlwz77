/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

/*
    traverse the list and create a new node for each node
    copy val, and set random to original list's node
    also link them during this
    using a hash map<pointer, pointer> {original, new}
    traverse list again and update random pointer
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newHead = new Node(0);
        Node* tmp = newHead;
        unordered_map<Node*, Node*> old2new;

        while (head != nullptr) {
            Node* newNode = new Node(head->val);
            old2new[head] = newNode;
            newNode->random = head->random;
            tmp->next = newNode;
            tmp = tmp->next;
            head = head->next;
        }

        tmp = newHead->next;
        while (tmp) {
            tmp->random = old2new[tmp->random];
            tmp = tmp->next;
        }

        return newHead->next;
    }
};
