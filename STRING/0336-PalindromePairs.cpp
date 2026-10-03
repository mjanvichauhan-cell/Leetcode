class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++)
            mp[words[i]] = i;
        for (int i = 0; i < words.size(); i++) {
            string s = words[i];
            int n = s.size();
            for (int j = 0; j <= n; j++) {
                string left = s.substr(0, j);
                string right = s.substr(j);
                if (isPalindrome(left)) {
                    string rev = right;
                    reverse(rev.begin(), rev.end());
                    if (mp.count(rev) && mp[rev] != i)
                        ans.push_back({mp[rev], i});
                }
                if (j != n && isPalindrome(right)) {
                    string rev = left;
                    reverse(rev.begin(), rev.end());
                    if (mp.count(rev) && mp[rev] != i)
                        ans.push_back({i, mp[rev]});
                }
            }
        }
        return ans;
    }
private:
    bool isPalindrome(string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
};