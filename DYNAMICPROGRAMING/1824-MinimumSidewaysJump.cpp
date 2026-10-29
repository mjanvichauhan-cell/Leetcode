class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size() - 1;
        vector<int> next(4, 0), curr(4, 0);
        for (int pos = n - 1; pos >= 0; pos--) {
            for (int lane = 1; lane <= 3; lane++) {
                if (obstacles[pos + 1] != lane) {
                    curr[lane] = next[lane];
                } else {
                    int ans = INT_MAX;
                    for (int i = 1; i <= 3; i++) {
                        if (i != lane && obstacles[pos] != i)
                            ans = min(ans, 1 + next[i]);
                    }
                    curr[lane] = ans;
                }
            }
            next = curr;
        }
        return min(next[2], min(1 + next[1], 1 + next[3]));
    }
};