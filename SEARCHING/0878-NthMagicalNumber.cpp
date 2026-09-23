class Solution {
public:
    static constexpr long long MOD = 1000000007;
    long long gcd(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long lcm =
            (long long)a / gcd(a, b) * b;
        long long lo = min(a, b);
        long long hi = lo * n;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            long long count =
                mid / a +
                mid / b -
                mid / lcm;
            if (count >= n)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo % MOD;
    }
};