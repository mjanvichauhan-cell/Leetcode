class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> board(3, vector<int>(3, 0));

        for (int i = 0; i < moves.size(); i++) {
            int r = moves[i][0];
            int c = moves[i][1];
            board[r][c] = (i % 2 == 0) ? 1 : 2;
        }

        // Check rows
        for (int i = 0; i < 3; i++) {
            if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return board[i][0] == 1 ? "A" : "B";
            }
        }

        // Check columns
        for (int j = 0; j < 3; j++) {
            if (board[0][j] != 0 && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
                return board[0][j] == 1 ? "A" : "B";
            }
        }

        // Diagonal
        if (board[0][0] != 0 && board[0][0] == board[1][1] &&  board[1][1] == board[2][2]) {
            return board[0][0] == 1 ? "A" : "B";
        }

        // Anti-diagonal
        if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
             return board[0][2] == 1 ? "A" : "B";
        }

        if (moves.size() == 9)
            return "Draw";

        return "Pending";
    }
};