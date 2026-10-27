class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> next = triangle[n - 1];
        vector<int> curr(n, 0);
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                int down = triangle[i][j] + next[j];
                int diagonal = triangle[i][j] + next[j + 1];
                curr[j] = min(down, diagonal);
            }
            next = curr;
        }
        return next[0];
    }
};