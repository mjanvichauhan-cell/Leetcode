class Solution {
public:
     bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) {
                vector<int> a(nums), b(nums);
                a.erase(a.begin() + i - 1);
                b.erase(b.begin() + i);
                return isIncreasing(a) || isIncreasing(b);
            }
        }
        return true;
    }
private:
    bool isIncreasing(vector<int>& v) {
        for (size_t i = 1; i < v.size(); i++)
            if (v[i] <= v[i - 1]) return false;
        return true;
    }
};