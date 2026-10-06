class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> used(26, false);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        string st;
        for (char ch : s) {
            int index = ch - 'a';
            freq[index]--;
            if (used[index]) {
                continue;
            }
            while (!st.empty() &&
                   st.back() > ch &&
                   freq[st.back() - 'a'] > 0) {
                used[st.back() - 'a'] = false;
                st.pop_back();
            }
            st.push_back(ch);
            used[index] = true;
        }
        return st;
    }
};