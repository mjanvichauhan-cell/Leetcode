class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> primes;
        for (int n : nums) {
            for (int p = 2; p * p <= n; p++) {
                if (n % p == 0) {
                    primes.insert(p);
                    while (n % p == 0) {
                        n /= p;
                    }
                }
            }
            if (n > 1) {
                primes.insert(n);
            }
        }
        return primes.size();
    }
};