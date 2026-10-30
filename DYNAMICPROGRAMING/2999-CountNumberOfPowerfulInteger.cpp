class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish,int limit, string s) {
        return solve(finish, limit, s) - solve(start - 1, limit, s);
    }

    long long solve(long long x, int limit, string s) {
        if (x < 0) return 0;
        string str = to_string(x);
        int n = str.size();
        int m = s.size();
        if (n < m) return 0;
        long long ans = 0;
        for (int len = m; len < n; len++) {
            int prefixLen = len - m;
            if (prefixLen == 0) {
                ans++;
            } else {
                ans += (long long)limit *
                       pow(limit + 1, prefixLen - 1);
            }
        }

        int prefixLen = n - m;
        if (prefixLen == 0) {
            if (str >= s)
                ans++;
            return ans;
        }

        long long prefix = stoll(str.substr(0, prefixLen));
        string p = to_string(prefix);
        for (int i = 0; i < prefixLen; i++) {
            int digit = p[i] - '0';
            int smaller;
            if (i == 0)
                smaller = min(digit - 1, limit);
            else
                smaller = min(digit, limit + 1);
            if (smaller > 0) {
                ans += (long long)smaller * pow(limit + 1, prefixLen - i - 1);
            }
            if (digit > limit)
                return ans;
        }
        string suffix = str.substr(prefixLen);
        if (suffix >= s)
            ans++;
        return ans;
    }

    long long pow(long long base, int exp) {
        long long res = 1;
        while (exp--) {
            res *= base;
        }
        return res;
    }
};