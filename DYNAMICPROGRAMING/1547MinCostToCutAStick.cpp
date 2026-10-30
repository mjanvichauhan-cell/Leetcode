class Solution {
public:
    int solve(int i,int j, vector<int>& cuts, vector<vector<int>>& dp){
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<=j;k++){
            int cost= cuts[j+1]-cuts[i-1] +solve(i,k-1,cuts,dp) +solve(k+1,j,cuts,dp);
            ans=min(ans,cost);
        }
        return dp[i][j]=ans;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        vector<vector<int>> dp(m, vector<int>(m,-1));
        return solve(1,m-2,cuts,dp);
    }
};