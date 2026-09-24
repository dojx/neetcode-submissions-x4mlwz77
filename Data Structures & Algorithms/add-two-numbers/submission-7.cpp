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
    two pointers
    loop until either p1 or p2 is null
        sum = p1 + p2 + carry
        carry = sum % 9
        res = new node(sum)
    
    while p1:
        sum = p1 + carry
        carry = sum % 9
        res = new node(sum)
        p1 = p1 next

    return res->next

*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2, *p3 = new ListNode(0);
        ListNode *curr = p3;
        int carry = 0;

        while (p1 || p2) {
            int sum = carry;
            if (p1 != nullptr) {
                sum += p1->val;
                p1 = p1->next;
            }
            if (p2 != nullptr) {
                sum += p2->val;
                p2 = p2->next;
            }
            carry = sum / 10;
            sum %= 10;
            curr->next = new ListNode(sum);
            curr = curr->next;
        }

        if (carry > 0) {
            curr->next = new ListNode(carry);
        }

        return p3->next;
    }
};
