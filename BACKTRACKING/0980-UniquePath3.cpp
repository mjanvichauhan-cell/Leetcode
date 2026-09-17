class Solution {
public:
    int ans = 0;
    void solve(vector<vector<int>>& grid,int row,int col,int remaining) {
        int m = grid.size();
        int n = grid[0].size();
        if (row < 0 || row >= m || col < 0 || col >= n)
            return;
        if (grid[row][col] == -1)
            return;
        if (grid[row][col] == 2) {
            if (remaining == 1)
                ans++;
            return;
        }
        int temp = grid[row][col];
        grid[row][col] = -1;
        solve(grid, row - 1, col, remaining - 1);
        solve(grid, row + 1, col, remaining - 1);
        solve(grid, row, col - 1, remaining - 1);
        solve(grid, row, col + 1, remaining - 1);
        grid[row][col] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int startRow = 0;
        int startCol = 0;
        int empty = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != -1)
                    empty++;
                if (grid[i][j] == 1) {
                    startRow = i;
                    startCol = j;
                }
            }
        }

        solve(grid, startRow, startCol, empty);
        return ans;
    }
};