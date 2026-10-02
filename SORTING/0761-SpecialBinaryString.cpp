class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> parts;
        int balance = 0;
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                balance++;
            else
                balance--;
            if (balance == 0) {
                string inner = s.substr(start + 1, i - start - 1);
                string solved = makeLargestSpecial(inner);
                parts.push_back("1" + solved + "0");
                start = i + 1;
            }
        }
        sort(parts.rbegin(), parts.rend());
        string ans;
        for (string &x : parts)
            ans += x;

        return ans;
    }
};