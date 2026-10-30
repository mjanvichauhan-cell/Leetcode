class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int currsum=0,mxsum=INT_MIN;
    for(int val:nums){
        currsum+=val;
        mxsum=max(mxsum,currsum);
        if(currsum<0){
           currsum=0;
        }
      }
    return mxsum;
    }
};