class Solution {
public:
    bool canPlace(vector<int>& position, int m, int dist) {
        int count = 1;
        int last = position[0];
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - last >= dist) {
                count++;
                last = position[i];
                if (count >= m)
                    return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int lo = 1;
        int hi = position.back() - position.front();
        int ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canPlace(position, m, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};