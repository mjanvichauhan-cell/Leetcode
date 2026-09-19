class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        vector<int> arr{2,3,5};
        for (int p : arr) {
            while (n % p == 0)
             n /= p;
        }
        return n == 1;
    }
};