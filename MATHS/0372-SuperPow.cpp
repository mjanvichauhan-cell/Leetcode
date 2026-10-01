class Solution {
public:
    static const int MOD = 1337;
    int modPow(int a, int b) {
        long long result = 1;
        a %= MOD;
        while (b > 0) {
            if (b & 1)
                result = result * a % MOD;
            a = (long long)a * a % MOD;
            b >>= 1;
        }
        return result;
    }

    int superPow(int a, vector<int>& b) {
        int result = 1;
        for (int digit : b) {
            result = modPow(result, 10);
            result = (long long)result * modPow(a, digit) % MOD;
        }
        return result;
    }
};