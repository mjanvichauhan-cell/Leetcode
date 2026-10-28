class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int coin : coins) {
            for (int amt = coin; amt <= amount; amt++) {
                dp[amt] = min(dp[amt], 1 + dp[amt - coin]);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};