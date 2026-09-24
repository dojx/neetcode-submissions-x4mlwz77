/*
    1->2->3->2->2
    p1 = 1, p2 = 2
    p1 = 2, p2 = 2

    1->2->3->4->4
    p1 = 1, p2 = 2
    p1 = 2, p2 = 4
    p1 = 3, p2 = 

    1->3->4->2->2
    p1 = 1, p2 = 3
    p1 = 3, p2 = 4
    p1 = 2, p2 = 4
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int p1 = 0, p2 = 0;

        while (1) {
            p1 = nums[p1];
            p2 = nums[nums[p2]];
            if (p1 == p2) break;
        }

        int p3 = 0;
        while (1) {
            p1 = nums[p1];
            p3 = nums[p3];
            if (p1 == p3) return p1;
        }
    }
};
