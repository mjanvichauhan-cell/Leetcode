class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        vector<pair<int, int>> dir = {
            {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1},  {1,0},  {1,1}
        };
        queue<pair<pair<int,int>, int>> q;
        q.push({{0,0},1});
        grid[0][0] = 1;  
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int x = front.first.first;
            int y = front.first.second;
            int dist = front.second;
            if (x == n - 1 && y == n - 1)
                return dist;
            for (auto d : dir) {
                int nx = x + d.first;
                int ny = y + d.second;
                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    grid[nx][ny] == 0) {
                    grid[nx][ny] = 1;
                    q.push({{nx, ny}, dist + 1});
                }
            }
        }
        return -1;
    }
};