class Solution {
public:
    bool isPalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(int i,string &s, vector<int>& dp){
        int n=s.size();
        if(i==n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                ans=min(ans,1+solve(j+1,s,dp));
            }
        }
        return dp[i]=ans;
    }
    int minCut(string s) {
        vector<int> dp(s.size(),-1);
        return solve(0,s,dp)-1;
    }
};