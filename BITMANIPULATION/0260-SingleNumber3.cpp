class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    long long ans=0;
    for(int i=0;i<nums.size();i++){
        ans^=nums[i];
    }
    long long diff= ans&-ans;
    int a=0,b=0;
    for(int x:nums){
        if(x&diff) a^=x;
        else b^=x;
    }
    return {a,b};
    }
};