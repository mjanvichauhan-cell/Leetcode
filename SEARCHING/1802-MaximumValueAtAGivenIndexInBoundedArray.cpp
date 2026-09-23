class Solution {
public:
    long long calc(long long peak, int len) {
        if (peak > len)
            return (peak + peak - len + 1) * len / 2;
        else
            return (peak + 1) * peak / 2 + (len - peak);
    }

    int maxValue(int n, int index, int maxSum) {
        int low = 1, high = maxSum;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long left = calc(mid - 1, index);
            long long right = calc(mid - 1, n - index - 1);
            long long total = left + right + mid;
            if (total <= maxSum)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};