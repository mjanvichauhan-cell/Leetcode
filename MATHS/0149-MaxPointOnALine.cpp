class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2)
            return n;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<string, int> mp;
            int best = 0;
            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                if (dx == 0) {
                    dy = 1;
                    dx = 0;
                }
                else if (dy == 0) {
                    dy = 0;
                    dx = 1;
                }
                else {
                    int g = gcd(abs(dx), abs(dy));
                    dx /= g;
                    dy /= g;
                    if (dx < 0) {
                        dx *= -1;
                        dy *= -1;
                    }
                }
                string key =
                    to_string(dy) + "/" + to_string(dx);
                mp[key]++;
                best = max(best, mp[key]);
            }
            ans = max(ans, best + 1);
        }
        return ans;
    }
};