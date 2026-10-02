class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k) {
            int left = i, right = min(i + k, n) - 1;
            while (left < right) swap(s[left++], s[right--]);
        }
        return s;
    }
};