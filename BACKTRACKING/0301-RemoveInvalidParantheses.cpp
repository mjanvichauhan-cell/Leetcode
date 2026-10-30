class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> vis;
        int left = 0, right = 0;
        for (char c : s) {
            if (c == '(')
                left++;
            else if (c == ')') {
                if (left > 0)
                    left--;
                else
                    right++;
            }
        }
        dfs(s, 0, left, right, ans, vis);
        return ans;
    }

private:
    bool valid(string s) {
        int count = 0;
        for (char c : s) {
            if (c == '(')
                count++;
            else if (c == ')') {
                count--;
                if (count < 0)
                    return false;
            }
        }
        return count == 0;
    }

    void dfs(string s, int pos, int left, int right,
             vector<string>& ans, unordered_set<string>& vis) {
        if (left == 0 && right == 0) {
            if (valid(s))
                ans.push_back(s);
            return;
        }
        for (int i = pos; i < s.size(); i++) {
            if (i > pos && s[i] == s[i - 1])
                continue;
            if (s[i] != '(' && s[i] != ')')
                continue;
            if (s[i] == '(' && left > 0) {
                string temp = s.substr(0, i) + s.substr(i + 1);

                if (!vis.count(temp)) {
                    vis.insert(temp);
                    dfs(temp, i, left - 1, right, ans, vis);
                }
            }
            if (s[i] == ')' && right > 0) {
                string temp = s.substr(0, i) + s.substr(i + 1);
                if (!vis.count(temp)) {
                    vis.insert(temp);
                    dfs(temp, i, left, right - 1, ans, vis);
                }
            }
        }
    }
};