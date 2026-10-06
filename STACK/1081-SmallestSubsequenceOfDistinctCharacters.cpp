class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(256, -1);
        vector<bool> used(256, false);
        for (int i = 0; i < s.size(); i++) {
            last[s[i]] = i;
        }
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (used[c])
                continue;
            while (!st.empty() &&
                   st.top() > c &&
                   last[st.top()] > i) {
                used[st.top()] = false;
                st.pop();
            }
            st.push(c);
            used[c] = true;
        }
        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};