class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<bool> next(m + 1, false), curr(m + 1, false);
        next[m] = true;
        for (int j = m - 1; j >= 0; j--)
            next[j] = (p[j] == '*') && next[j + 1];
        for (int i = n - 1; i >= 0; i--) {
            curr[m] = false;
            for (int j = m - 1; j >= 0; j--) {
                if (p[j] == s[i] || p[j] == '?')
                    curr[j] = next[j + 1];
                else if (p[j] == '*')
                    curr[j] = next[j] || curr[j + 1];
                else
                    curr[j] = false;
            }
            next = curr;
        }
        return next[0];
    }
};