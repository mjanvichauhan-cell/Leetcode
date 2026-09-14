class Solution {
public:
 int countbits(int x){
        int cnt = 0;
        while(x){
            cnt += x & 1;
            x >>= 1;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
          vector<int> ans(n + 1);
        for(int i = 0; i <= n; i++)
            ans[i] = countbits(i);
        return ans;
    }
};