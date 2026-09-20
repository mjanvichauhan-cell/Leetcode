class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int i=0;
        int pos=0;
        int neg=1;

        while(i<nums.size()){
            if(nums[i]%2==0){
                ans[pos]=nums[i];
                pos+=2;
            }
            if(nums[i]%2!=0){
                ans[neg]=nums[i];
                neg+=2;
            }
            i++;

        }
        return ans;
    }
};