/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
    traverse list once to count nodes
    dest = nodeCount - n
    stop 1 node before dest, skip next node
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tmp = head;
        int nodeCount = 0;
        while (tmp) {
            tmp = tmp->next;
            nodeCount++;
        }

        int dest = nodeCount - n;

        if (dest == 0) {
            ListNode *tmp2 = head->next;
            delete head;
            return tmp2;
        } else {
            tmp = head;
            while (dest - 1) {
                tmp = tmp->next;
                dest--;
            }

            ListNode *tmp2 = tmp->next;
            tmp->next = tmp2->next;
            delete tmp2;

            return head;
        }
    }
};
