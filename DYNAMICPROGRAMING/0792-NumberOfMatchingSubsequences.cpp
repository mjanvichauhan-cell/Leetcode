class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.size(); i++) {
            pos[s[i] - 'a'].push_back(i);
        }
        int ans = 0;
        for (string &word : words) {
            int prev = -1;
            bool ok = true;
            for (char c : word) {
                auto &v = pos[c - 'a'];
                auto it = upper_bound(v.begin(), v.end(), prev);
                if (it == v.end()) {
                    ok = false;
                    break;
                }
                prev = *it;
            }
            if (ok)
                ans++;
        }
        return ans;
    }
};