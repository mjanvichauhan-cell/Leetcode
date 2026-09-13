class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = 0;
                // Count live neighbours
                for (int d = 0; d < 8; d++) {
                    int ni = i + dr[d];
                    int nj = j + dc[d];
                    if (ni >= 0 && ni < m &&
                        nj >= 0 && nj < n &&
                        abs(board[ni][nj]) == 1) {
                        live++;
                    }
                }
                // Live cell
                if (board[i][j] == 1) {
                    if (live < 2 || live > 3)
                        board[i][j] = -1; // dies
                }
                // Dead cell
                else {
                    if (live == 3)
                        board[i][j] = 2; // becomes alive
                }
            }
        }
        // Convert temporary states to final states
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == -1)
                    board[i][j] = 0;
                else if (board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
    }
};