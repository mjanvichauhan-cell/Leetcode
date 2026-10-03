class Solution {
public:
    bool isAnagram(string s1, string s2) {
            vector<int> freq(26,0);
    if(s1.length()!=s2.length()) return false ;
    for(int i=0;i<s1.length();i++){
        freq[s2[i]-'a']--;
        freq[s1[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(freq[i]!=0){
            return false;
        }
    }
    return true;
    }
};