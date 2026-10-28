class Solution {
public:
    int numTilings(int n) {
        const long long MOD = 1e9 + 7;
        if (n == 1) return 1;
        if (n == 2) return 2;
        long long a = 1; // dp[1]
        long long b = 2; // dp[2]
        long long c = 5; // dp[3]
        for (int i = 4; i <= n; i++) {
            long long d = (2 * c + a) % MOD;
            a = b;
            b = c;
            c = d;
        }
        return c;
    }
};