class Solution {
public:
    int solve(vector<int>& nums,int val){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]+val-1)/val;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=0;
        for(int i=0;i<nums.size();i++){
            high=max(high,nums[i]);
        }
        int ans=1e9;
        while(low<=high){
            int mid=low+(high-low)/2;
            int val=solve(nums,mid);

            if(val>threshold){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};
