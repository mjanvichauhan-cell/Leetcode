class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int option1 = costs[0] + dp[i + 1];
            int j = i;
            while (j < n && days[j] < days[i] + 7)
                j++;
            int option2 = costs[1] + dp[j];
            j = i;
            while (j < n && days[j] < days[i] + 30)
                j++;
            int option3 = costs[2] + dp[j];
            dp[i] = min(option1, min(option2, option3));
        }
        return dp[0];
    }
};