class Solution {
public:
    int findPeakElement(vector<int>& v) {
    int n = v.size();

    if (n == 1) return 0;

    int lo = 0;
    int hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (mid == 0) {
            if (v[mid] > v[mid + 1]) return 0;
            else lo = mid + 1;
        }
        else if (mid == n - 1) {
            if (v[mid] > v[mid - 1]) return n - 1;
            else hi = mid - 1;
        }
        else {
            if (v[mid] > v[mid - 1] && v[mid] > v[mid + 1])
                return mid;
            else if (v[mid] > v[mid - 1])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
    }
    return -1;
}
};