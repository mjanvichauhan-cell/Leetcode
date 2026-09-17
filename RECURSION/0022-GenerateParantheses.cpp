class Solution {
public:
    void solve(int open, int close, string output, vector<string> &ans) {
    if (open == 0 && close == 0) {
        ans.push_back(output);
        return;
    }
    if (open > 0) {
        solve(open - 1, close, output + "(", ans);
    }
    if (close > open) {
        solve(open, close - 1, output + ")", ans);
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    solve(n, n, "", ans);
    return ans;
}
};