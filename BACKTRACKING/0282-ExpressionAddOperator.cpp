class Solution {
public:
    void solve(string &num, int target, int index,
               string path, long long value,
               long long prev, vector<string> &ans) {
        if (index == num.size()) {
            if (value == target)
                ans.push_back(path);
            return;
        }
        long long curr = 0;
        for (int i = index; i < num.size(); i++) {
            if (i > index && num[index] == '0')
                break;
            curr = curr * 10 + (num[i] - '0');
            string currStr = num.substr(index, i - index + 1);
            if (index == 0) {
                solve(num, target, i + 1,currStr,curr,curr,ans);
            }
            else {
                solve(num, target, i + 1,path + "+" + currStr, value + curr, curr, ans);
                solve(num, target, i + 1,path + "-" + currStr,value - curr,-curr,ans);
                solve(num, target, i + 1,path + "*" + currStr,value - prev + prev * curr,prev * curr, ans);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(num, target, 0, "", 0, 0, ans);
        return ans;
    }
};