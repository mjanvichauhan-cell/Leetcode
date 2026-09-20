class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
    int mid=0;
    int h=nums.size()-1;
    while(mid<=h){
        if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else {
            swap(nums[mid],nums[h]);
            h--;
        }
    }
    }
};