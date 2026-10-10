class Solution {
public:
    struct Node {
        Node* child[2] = {nullptr, nullptr};
        int cnt = 0;
    };
    Node* root = new Node();
    void insert(int x) {
        Node* cur = root;
        cur->cnt++;
        for (int i = 30; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (!cur->child[bit])
                cur->child[bit] = new Node();
            cur = cur->child[bit];
            cur->cnt++;
        }
    }

    void remove(int x) {
        Node* cur = root;
        cur->cnt--;
        for (int i = 30; i >= 0; i--) {
            int bit = (x >> i) & 1;
            cur = cur->child[bit];
            cur->cnt--;
        }
    }

    int getMaxXor(int x) {
        Node* cur = root;
        int ans = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (cur->child[1 - bit] &&
                cur->child[1 - bit]->cnt > 0) {
                ans |= (1 << i);
                cur = cur->child[1 - bit];
            } 
            else {
                cur = cur->child[bit];
            }
        }
        return ans;
    }

    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            while (left < right &&
                   nums[right] - nums[left] > nums[left]) {
                remove(nums[left]);
                left++;
            }
            insert(nums[right]);
            ans = max(ans, getMaxXor(nums[right]));
        }

        return ans;
    }
};