class Solution {
public:
    static bool comp(string &a, string &b) {
        return a.size() < b.size();
    }
    bool check(string &s1, string &s2) {
        if (s1.size() != s2.size() + 1)
            return false;
        int i = 0, j = 0;
        while (i < s1.size()) {
            if (j < s2.size() && s1[i] == s2[j]) {
                i++;
                j++;
            }
            else {
                i++;
            }
        }
        return i == s1.size() && j == s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        int n = words.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (check(words[i], words[j]) &&
                    dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};