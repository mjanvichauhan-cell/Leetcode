class Solution {
public:
    string toHex(int num) {
    unsigned int n = num;
    unsigned int x = 1;
    string ans="";
    if(n==0) return "0";
    while(n>0){
        int ld=n%16;
        n/=16;
        if(ld<=9) ans=ans+to_string(ld);
        else{
            char c='a'+ld-10;
            ans.push_back(c);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};