class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return solve(s, i);
    }

    string solve(string &s, int &i) {
        string curr = "";
        while (i < s.length() && s[i] != ']') {
            if (isdigit(s[i])) {
                int num = 0;
                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i++;
                string inside = solve(s, i);
                i++;
                while (num--) {
                    curr += inside;
                }
            }
            else {
                curr += s[i];
                i++;
            }
        }
        return curr;
    }
};