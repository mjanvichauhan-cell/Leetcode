class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        unordered_map<int, int> cnt;
        for (int x : hand) cnt[x]++;
        sort(hand.begin(), hand.end());
        for (int x : hand) {
            if (cnt[x] == 0) continue;
            for (int i = 0; i < groupSize; i++) {
                if (cnt[x + i] == 0) return false;
                cnt[x + i]--;
            }
        }
        return true;
    }
};