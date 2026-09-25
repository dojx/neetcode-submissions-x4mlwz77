/*
    binary search m on array [1, max(piles)]
    check if its possible to finish all piles in h hours at a rate of m
        - time to finish = ceil(pileSize / m) = (pileSize + 1) / m
        - traverse through list takes n time
        - binary search takes log(m) time
        - time complexity = O(nlogm)
    if yes, search right, else search left
    return last element that fulfills requirement
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxK = *(max_element(piles.begin(), piles.end()));
        int l = 1, r = maxK - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            long long time = 0;
            for (int n : piles) {
                time += (n + m - 1) / m;
            }
            if (time > h) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return l;
    }
};
