class Solution {
public:
    string process(string s) {
        string st;
        for (char ch : s) {
            if (ch == '#') {
                if (!st.empty()) {
                    st.pop_back();
                }
            }
            else {
                st.push_back(ch);
            }
        }
        return st;
    }
    bool backspaceCompare(string s, string t) {
        return process(s) == process(t);
    }
};