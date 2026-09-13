class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int total = rows * cols;
        int r = rStart, c = cStart;
        ans.push_back({r, c});
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        int dir = 0;
        int step = 1;
        while (ans.size() < total) {
            for (int repeat = 0; repeat < 2; repeat++) {
                for (int i = 0; i < step; i++) {
                    r += dr[dir];
                    c += dc[dir];
                    if (r >= 0 && r < rows && c >= 0 && c < cols) {
                        ans.push_back({r, c});
                    }
                }
                dir = (dir + 1) % 4;
            }
            step++;
        }
        return ans;
    }
};