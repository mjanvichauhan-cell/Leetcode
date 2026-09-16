//Method1
  class Solution {
public:
    bool isSafe(int x, int y, vector<vector<char>>& board,
                vector<vector<int>>& vis, string &word, int index) {
        return (x >= 0 && y >= 0 &&
                x < board.size() && y < board[0].size() &&
                vis[x][y] == 0 &&
                board[x][y] == word[index]);
    }

    bool solve(int x, int y, vector<vector<char>>& board,
               vector<vector<int>>& vis, string &word, int index) {
        if (index == word.size())
            return true;
        if (!isSafe(x, y, board, vis, word, index))
            return false;
        vis[x][y] = 1;
        if (solve(x + 1, y, board, vis, word, index + 1))
            return true;
        if (solve(x - 1, y, board, vis, word, index + 1))
            return true;
        if (solve(x, y + 1, board, vis, word, index + 1))
            return true;
        if (solve(x, y - 1, board, vis, word, index + 1))
            return true;
        vis[x][y] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    for (auto &row : vis)
                        fill(row.begin(), row.end(), 0);
                    if (solve(i, j, board, vis, word, 0))
                        return true;
                }
            }
        }
        return false;
    }

};

//Method2
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string &word, int row, int col, int index) {
    if (index == word.size())
            return true;
    if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[index])
            return false;
    char temp = board[row][col];
    board[row][col] = '#';
    bool found =
            dfs(board, word, row + 1, col, index + 1) ||
            dfs(board, word, row - 1, col, index + 1) ||
            dfs(board, word, row, col + 1, index + 1) ||
            dfs(board, word, row, col - 1, index + 1);
        board[row][col] = temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for (int i = 0; i <n; i++) {
            for (int j = 0; j <m; j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
    return false;
    }
};