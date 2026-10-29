class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> maxi(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            maxi[i][i] = arr[i];
            for (int j = i + 1; j < n; j++)
                maxi[i][j] = max(maxi[i][j - 1], arr[j]);
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], maxi[i][k] * maxi[k + 1][j] + dp[i][k] + dp[k + 1][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};