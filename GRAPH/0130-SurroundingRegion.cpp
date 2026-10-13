class Solution {
public:
    int m, n;
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    void dfs(vector<vector<char>>& board, int x, int y) {
        board[x][y] = 'T';
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                board[nx][ny] == 'O') {
                dfs(board, nx, ny);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0);

            if (board[i][n - 1] == 'O')
                dfs(board, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')
                dfs(board, 0, j);
            if (board[m - 1][j] == 'O')
                dfs(board, m - 1, j);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }
};