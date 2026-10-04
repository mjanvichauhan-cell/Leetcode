class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int start = 0;
        for (int end = 0; end <= s.size(); end++) {
            if (end == s.size() || s[end] == ' ') {
                if (start < end) {
                    reverse(s.begin() + start, s.begin() + end);
                }
                start = end + 1;
            }
        }
        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (!ans.empty())
                    ans += ' ';
                while (i < s.size() && s[i] != ' ') {
                    ans += s[i];
                    i++;
                }
            }
        }
        return ans;
    }
};