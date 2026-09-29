class Solution {
public:
    vector<int> ans;
    void mergeSort(vector<pair<int,int>>& a, int l, int r) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        vector<pair<int,int>> temp;
        int i = l, j = mid + 1;
        int rightCount = 0;
        while (i <= mid && j <= r) {
            if (a[j].first < a[i].first) {
                rightCount++;
                temp.push_back(a[j++]);
            } else {
                ans[a[i].second] += rightCount;
                temp.push_back(a[i++]);
            }
        }
        while (i <= mid) {
            ans[a[i].second] += rightCount;
            temp.push_back(a[i++]);
        }
        while (j <= r)
            temp.push_back(a[j++]);
        for (int k = l; k <= r; k++)
            a[k] = temp[k - l];
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans.assign(n, 0);
        vector<pair<int,int>> a;
        for (int i = 0; i < n; i++)
            a.push_back({nums[i], i});
        mergeSort(a, 0, n - 1);
        return ans;
    }
};