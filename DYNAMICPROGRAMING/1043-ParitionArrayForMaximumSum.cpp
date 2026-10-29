class Solution {
public:
    int solve(int i, vector<int>& arr, int k, vector<int>& dp){
        int n = arr.size();
        if(i == n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int len = 0;
        int maxi = INT_MIN;
        int ans = INT_MIN;
        for(int j = i; j < min(n, i + k); j++){
            len++;
            maxi = max(maxi, arr[j]);
            ans = max(ans, len * maxi + solve(j + 1, arr, k, dp));
        }
        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        return solve(0, arr, k, dp);
    }
};