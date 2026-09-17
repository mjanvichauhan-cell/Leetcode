class Solution {
public:
    int solve(int i, int n, int start) {
        if (i == n)
            return 0;
        int current = start + 2 * i;
        return current ^ solve(i + 1, n, start);
    }
    int xorOperation(int n, int start) {
        return solve(0, n, start);
    }
};