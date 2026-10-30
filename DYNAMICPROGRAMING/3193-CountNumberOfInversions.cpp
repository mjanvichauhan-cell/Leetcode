class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        const int MOD = 1e9 + 7;
        int maxInv = 400;
        vector<int> req(n, -1);
        for (auto &x : requirements)
            req[x[0]] = x[1];
        vector<vector<int>> dp(n + 1, vector<int>(maxInv + 1, 0));
        dp[0][0] = 1;
        for (int len = 1; len <= n; len++) {
            for (int inv = 0; inv <= maxInv; inv++) {
                long long ways = 0;
                for (int add = 0; add <= len - 1 && inv >= add; add++) {
                    ways += dp[len - 1][inv - add];
                    ways %= MOD;
                }
                dp[len][inv] = ways;
            }
            if (req[len - 1] != -1) {
                for (int inv = 0; inv <= maxInv; inv++) {
                    if (inv != req[len - 1])
                        dp[len][inv] = 0;
                }
            }
        }

        long long ans = 0;
        for (int x : dp[n])
            ans = (ans + x) % MOD;
        return ans;
    }
};