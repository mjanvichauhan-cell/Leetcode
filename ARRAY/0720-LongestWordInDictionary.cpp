class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        string ans = "";
        for (string word : words) {
            bool valid = true;
            string prefix = "";
            for (char ch : word) {
                prefix += ch;
                if (st.find(prefix) == st.end()) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                if (word.length() > ans.length() ||
                    (word.length() == ans.length() && word < ans)) {
                    ans = word;
                }
            }
        }
        return ans;
    }
};