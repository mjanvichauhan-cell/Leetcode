class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     vector<int> dict(256,-1);
    int maxlne=0,st=-1;
    for(int i=0;i<s.size();i++){
        if(dict[s[i]]>st){
            st=dict[s[i]];}
            dict[s[i]]=i;
            maxlne=max(maxlne,i-st);
    }
    return maxlne;
    }
};