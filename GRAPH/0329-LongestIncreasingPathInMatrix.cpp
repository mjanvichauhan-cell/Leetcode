class Solution {
public:
    int m, n;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& matrix,
            int x, int y) {
        if (dp[x][y] != 0)
            return dp[x][y];
        int best = 1;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= m ||  ny < 0 || ny >= n)
                continue;
            if (matrix[nx][ny] > matrix[x][y]) {
                best = max(
                    best,
                    1 + dfs(matrix, nx, ny)
                );
            }
        }
        return dp[x][y] = best;
    }
    int longestIncreasingPath(
        vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        dp.assign(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(
                    ans,
                    dfs(matrix, i, j)
                );
            }
        }
        return ans;
    }
};