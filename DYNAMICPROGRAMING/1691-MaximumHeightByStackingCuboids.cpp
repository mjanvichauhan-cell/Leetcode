class Solution {
public:
    int solve(int curr, int prev, vector<vector<int>>& cuboids, vector<vector<int>>& dp) {
        if (curr == cuboids.size())
            return 0;
        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];
        int notTake = solve(curr + 1, prev, cuboids, dp);
        int take = 0;
        if (prev == -1 ||
            (cuboids[curr][0] >= cuboids[prev][0] &&
             cuboids[curr][1] >= cuboids[prev][1] &&
             cuboids[curr][2] >= cuboids[prev][2])) {
            take = cuboids[curr][2] +
                   solve(curr + 1, curr, cuboids, dp);
        }
        return dp[curr][prev + 1] = max(take, notTake);
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto &c : cuboids)
            sort(c.begin(), c.end());
        sort(cuboids.begin(), cuboids.end());
        int n = cuboids.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, -1, cuboids, dp);
    }
};