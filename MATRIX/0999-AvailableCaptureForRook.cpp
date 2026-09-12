class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int r, c;
        // Find rook
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    r = i;
                    c = j;
                }
            }
        }
        int ans = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        // Explore 4 directions
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            while (nr >= 0 && nr < 8 &&
                   nc >= 0 && nc < 8) {
                if (board[nr][nc] == 'B')
                    break;
                if (board[nr][nc] == 'p') {
                    ans++;
                    break;
                }
                nr += dr[d];
                nc += dc[d];
            }
        }
        return ans;
    }
};