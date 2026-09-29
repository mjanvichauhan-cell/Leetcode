class Solution {
public:
    int lower, upper;
    long long mergeSort(vector<long long>& nums, int l, int r) {
        if (l >= r)
            return 0;
        int mid = l + (r - l) / 2;
        long long ans = mergeSort(nums, l, mid)  + mergeSort(nums, mid + 1, r);
        int j = mid + 1;
        int k = mid + 1;
        for (int i = l; i <= mid; i++) {
            while (j <= r &&
                   nums[j] - nums[i] < lower)
                j++;
            while (k <= r &&
                   nums[k] - nums[i] <= upper)
                k++;
            ans += k - j;
        }
        vector<long long> temp;
        int i = l;
        j = mid + 1;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }
        while (i <= mid)
            temp.push_back(nums[i++]);
        while (j <= r)
            temp.push_back(nums[j++]);
        for (int p = l; p <= r; p++)
            nums[p] = temp[p - l];
        return ans;
    }

    int countRangeSum(
        vector<int>& nums,
        int lower,
        int upper) {
        this->lower = lower;
        this->upper = upper;
        vector<long long> prefix(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++)
            prefix[i + 1] = prefix[i] + nums[i];
        return mergeSort(prefix, 0, prefix.size() - 1);
    }
};