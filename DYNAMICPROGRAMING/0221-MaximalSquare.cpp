class Solution {
public:
    int ans = 0;
    int solve(int i, int j, vector<vector<char>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();
        int m = matrix[0].size();
        if (i >= n || j >= m)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int right = solve(i, j + 1, matrix, dp);
        int down = solve(i + 1, j, matrix, dp);
        int diagonal = solve(i + 1, j + 1, matrix, dp);
        if (matrix[i][j] == '1') {
            dp[i][j] = 1 + min({right, down, diagonal});
            ans = max(ans, dp[i][j]);
        } else {
            dp[i][j] = 0;
        }
        return dp[i][j];
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        solve(0, 0, matrix, dp);
        return ans * ans;
    }
};