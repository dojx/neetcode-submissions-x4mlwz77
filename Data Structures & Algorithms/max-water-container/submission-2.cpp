class Solution {
public:
    int maxArea(vector<int>& heights) {
        /*
            constraints: n = 10^5
            input: array (unsorted)
            two pointers, greedy?

            area = (j - i) * (min(h[i], h[j]))

            lo = 0, hi = n - 1
            currMax


            currMax 
        */

       int left = 0, right = heights.size() - 1, currMax = 0;
       while (left < right) {
            int leftH = heights[left], rightH = heights[right];
            int area = (right - left) * min(leftH, rightH);
            if (area > currMax) {
                currMax = area;
            }
            if (leftH < rightH) {
                left++;
            } else {
                right--;
            }
       }
       return currMax;
    }
};
