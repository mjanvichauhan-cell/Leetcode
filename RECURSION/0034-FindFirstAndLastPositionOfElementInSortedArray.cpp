class Solution {
public:

    int firstPosition(vector<int>& nums, int target, int low, int high) {
        if (low > high)
            return -1;
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            int left = firstPosition(nums, target, low, mid - 1);
            if (left != -1)
                return left;
            return mid;
        }
        if (nums[mid] < target)
            return firstPosition(nums, target, mid + 1, high);
        return firstPosition(nums, target, low, mid - 1);
    }

    int lastPosition(vector<int>& nums, int target, int low, int high) {
        if (low > high)
            return -1;
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            int right = lastPosition(nums, target, mid + 1, high);
            if (right != -1)
                return right;
            return mid;
        }
        if (nums[mid] < target)
            return lastPosition(nums, target, mid + 1, high);
        return lastPosition(nums, target, low, mid - 1);
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = firstPosition(nums, target, 0, n - 1);
        int last = lastPosition(nums, target, 0, n - 1);
        return {first, last};
    }
};