class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> next(2, 0), curr(2, 0);
        for (int index = n - 1; index >= 0; index--) {
            curr[1] = max(-prices[index] + next[0], next[1]);
            curr[0] = max(prices[index] - fee + next[1], next[0]);
            next = curr;
        }
        return next[1];
    }
};