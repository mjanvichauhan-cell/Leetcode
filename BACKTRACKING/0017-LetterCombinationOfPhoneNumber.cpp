class Solution {
public:
    void f(string &s,int i,string result, vector<string> &li,vector<string> &v){
        if(i==s.size()){
          li.push_back(result);
          return;
        }
        int digit=s[i]-'0';
        if(digit<=1){
        f(s,i+1,result,li,v);
        return ;
     }
    for(int j=0;j<v[digit].size();j++){
        f(s,i+1,result+v[digit][j],li,v);
    }
    return;
}
    vector<string> letterCombinations(string digits) {
        vector<string> li;
        if (digits.size() == 0)
            return li;
        vector<string> v(10);
        v[2] = "abc";
        v[3] = "def";
        v[4] = "ghi";
        v[5] = "jkl";
        v[6] = "mno";
        v[7] = "pqrs";
        v[8] = "tuv";
        v[9] = "wxyz";
        f(digits, 0, "", li, v);
        return li; 
    }
};