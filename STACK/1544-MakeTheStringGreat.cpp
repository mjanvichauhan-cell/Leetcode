class Solution {
public:
    string makeGood(string s) {
        string st;
        for (char ch : s) {
            if (!st.empty() &&
                tolower(st.back()) == tolower(ch) &&
                st.back() != ch) {
                st.pop_back();
            } else {
                st.push_back(ch);
            }
        }
        return st;
    }
};