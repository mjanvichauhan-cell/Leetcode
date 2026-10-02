class Solution {
public:
   string sortSentence(string s) {
        vector<string> words(10);
        string temp = "";
        for (int i = 0; i <= s.length(); i++) {
            if (i == s.length() || s[i] == ' ') {
                int pos = temp[temp.length() - 1] - '0';
                temp.pop_back();
                words[pos] = temp;
                temp = "";
            }
            else {
                temp += s[i];
            }
        }
        string ans = "";
        for (int i = 1; i < 10; i++) {
            if (words[i] != "") {
                if (ans != "")
                    ans += " ";
                ans += words[i];
            }
        }
        return ans;
    }

};