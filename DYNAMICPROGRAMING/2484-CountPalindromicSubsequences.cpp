class Solution {
public:
    int countPalindromes(string s) {
        const int MOD = 1000000007;
        int n = s.size();
        vector<vector<long long>> pre1(n + 1, vector<long long>(10));
        vector<vector<vector<long long>>> pre2(n + 1, vector<vector<long long>>(10, vector<long long>(10)));
        for (int i = 0; i < n; i++) {
            pre1[i + 1] = pre1[i];
            pre2[i + 1] = pre2[i];
            int d = s[i] - '0';
            for (int x = 0; x < 10; x++)
                pre2[i + 1][x][d] = (pre2[i + 1][x][d] + pre1[i][x]) % MOD;
            pre1[i + 1][d]++;
        }
        vector<vector<long long>> suf1(n + 1, vector<long long>(10));
        vector<vector<vector<long long>>> suf2(n + 1, vector<vector<long long>>(10, vector<long long>(10)));
        for (int i = n - 1; i >= 0; i--) {
            suf1[i] = suf1[i + 1];
            suf2[i] = suf2[i + 1];
            int d = s[i] - '0';
            for (int x = 0; x < 10; x++)
                suf2[i][d][x] = (suf2[i][d][x] + suf1[i + 1][x]) % MOD;
            suf1[i][d]++;
        }
        long long ans = 0;
        for (int i = 2; i <= n - 3; i++) {
            for (int a = 0; a < 10; a++) {
                for (int b = 0; b < 10; b++) {
                    ans = (ans + pre2[i][a][b] * suf2[i + 1][b][a]) % MOD;
                }
            }
        }
        return ans;
    }
};