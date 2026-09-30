class Solution {
public:
  vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int n = left; n <= right; n++) {
            if (isSelfDividing(n)) res.push_back(n);
        }
        return res;
    }
private:
    bool isSelfDividing(int n) {
        int x = n;
        while (x > 0) {
            int d = x % 10;
            if (d == 0 || n % d != 0) return false;
            x /= 10;
        }
        return true;
    }
};