class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1000000007;
        vector<int> next(target + 1, 0), curr(target + 1, 0);
        next[0] = 1;
        for (int dice = 1; dice <= n; dice++) {
            fill(curr.begin(), curr.end(), 0);
            for (int t = 1; t <= target; t++) {
                long long ans = 0;
                for (int face = 1; face <= k; face++) {
                    if (t - face >= 0)
                        ans = (ans + next[t - face]) % MOD;
                }
                curr[t] = ans;
            }
            next = curr;
        }
        return next[target];
    }
};