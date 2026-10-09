class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size(), m = p.size();
        if (m > n) return ans;
        vector<int> freq(26, 0);
        for (char c : p) {
            freq[c - 'a']++;
        }
        for (int i = 0; i < m; i++) {
            freq[s[i] - 'a']--;
        }
        if (allZero(freq)) {
            ans.push_back(0);
        }
        for (int right = m; right < n; right++) {
            freq[s[right - m] - 'a']++;
            freq[s[right] - 'a']--;

            if (allZero(freq)) {
                ans.push_back(right - m + 1);
            }
        }
        return ans;
    }

private:
    bool allZero(vector<int>& freq) {
        for (int count : freq) {
            if (count != 0) return false;
        }
        return true;
    }
};