class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq;
        for (int x : nums) {
            pq.push(x);
        }
        long long score = 0
        while (k--) {
            long long x = pq.top();
            pq.pop();
            score += x;
            long long next = (x + 2) / 3;
            pq.push(next);
        }
        return score;
    }
};