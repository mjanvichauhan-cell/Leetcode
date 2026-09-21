class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int ele1 = 0, ele2 = 0;

        for (int x : nums) {
            if (cnt1 == 0 && x != ele2) {
                ele1 = x;
                cnt1 = 1;
            } else if (cnt2 == 0 && x != ele1) {
                ele2 = x;
                cnt2 = 1;
            } else if (x == ele1) {
                cnt1++;
            } else if (x == ele2) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        for (int x : nums) {
            if (x == ele1) cnt1++;
            else if (x == ele2) cnt2++;
        }

        vector<int> ans;
        int n = nums.size();
        if (cnt1 > n / 3) ans.push_back(ele1);
        if (cnt2 > n / 3) ans.push_back(ele2);

        return ans;
    }
};