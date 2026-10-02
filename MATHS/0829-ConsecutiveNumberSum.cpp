class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0;
        for (long long k = 1; k * (k + 1) / 2 <= n; k++) {
            long long remaining =  n - k * (k - 1) / 2;
            if (remaining > 0 && remaining % k == 0) {
                ans++;
            }
        }
        return ans;
    }
};