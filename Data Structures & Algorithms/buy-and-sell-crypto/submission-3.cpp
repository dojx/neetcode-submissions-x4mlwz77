class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            constraints: n^2
            input: array (unsorted)
            output: max value

            sliding window

            currMax = 0
            while r < length
            l = 0, r = 1
            if price[l] < price[r]:
                l = r
            else:
                r++
        */
        size_t pricesN = prices.size();
        if (pricesN < 2) {
            return 0;
        }

        int currMax = 0, l = 0, r = 1;
        while (r < pricesN) {
            int priceL = prices[l], priceR = prices[r];
            int profit = priceR - priceL;
            if (currMax < profit) {
                currMax = profit;
            }
            if (priceR < priceL) {
                l = r;
            }
            r++;
        }
        return currMax;
    }
};
