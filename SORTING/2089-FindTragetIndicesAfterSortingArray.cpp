class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int st=0,end=nums.size()-1;
        vector<int> ans;
        sort(nums.begin(),nums.end());
         for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target)
            ans.push_back(i);
    }
        return ans;
    }
};