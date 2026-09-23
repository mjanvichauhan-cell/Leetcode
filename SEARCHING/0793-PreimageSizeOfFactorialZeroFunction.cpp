class Solution {
public:
    long long trailingZeroes(long long x) {
        long long count = 0;
        while (x > 0) {
            x /= 5;
            count += x;
        }
        return count;
    }

    int preimageSizeFZF(int k) {
        long long lo = 0;
        long long hi = 5LL * (k + 1);
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (trailingZeroes(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        return trailingZeroes(lo) == k ? 5 : 0;
    }
};