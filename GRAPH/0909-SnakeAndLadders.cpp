class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> cells(n * n + 1);
        int idx = 1;
        bool leftToRight = true;
        for (int r = n - 1; r >= 0; r--) {
            if (leftToRight) {
                for (int c = 0; c < n; c++)
                    cells[idx++] = board[r][c];
            } else {
                for (int c = n - 1; c >= 0; c--)
                    cells[idx++] = board[r][c];
            }

            leftToRight = !leftToRight;
        }
        queue<int> q;
        vector<bool> visited(n * n + 1, false);
        q.push(1);
        visited[1] = true;
        int moves = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front();
                q.pop();
                if (curr == n * n)
                    return moves;
                for (int dice = 1; dice <= 6; dice++) {
                    int next = curr + dice;
                    if (next > n * n)
                        break;
                    if (cells[next] != -1)
                        next = cells[next];
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};