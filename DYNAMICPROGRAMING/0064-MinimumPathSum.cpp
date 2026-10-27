class Solution {
public:
    int f(vector<vector<int>>& grid,int m,int n,vector<vector<int>>& dp){
        if(m==0 && n==0)return grid[m][n];
        if(n<0 || m<0)return INT_MAX;
        int sum=0;
        if(dp[m][n]!=-1)return dp[m][n];
        int up=f(grid,m-1,n,dp);
        int left=f(grid,m,n-1,dp);
        sum=grid[m][n]+min(up,left);
        return dp[m][n]=sum;
    }    
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(grid,m-1,n-1,dp);
    }
};