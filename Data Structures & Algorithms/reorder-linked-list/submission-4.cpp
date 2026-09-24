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
    slow and fast
    stop fast when it is at the end or 1 spot before
    slow ends up at end of first half
    slow->next is start of second half
    separate list by pointing slow to nullptr
    reverse 2nd half
    interweave 1st and 2nd halves:
        l1 = head, l2
        l1_next = l1->next
        l2_next = l2->next
        l1->next = l2
        l2->next = l1_next
        l2 = l2_next
        l1 = l1_next

*/

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head->next) return;
        ListNode *slow = head, *fast = head->next;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *list2 = slow->next;
        slow->next = nullptr;
        ListNode *prev = nullptr;

        while (list2) {
            fast = list2->next;
            list2->next = prev;
            prev = list2;
            list2 = fast;
        }

        list2 = prev;
        ListNode* list1 = head;

        while (list1->next) {
            slow = list1->next;
            fast = list2->next;
            list1->next = list2;
            list2->next = slow;
            list1 = slow;
            list2 = fast;
        }

        list1->next = list2;
    }
};