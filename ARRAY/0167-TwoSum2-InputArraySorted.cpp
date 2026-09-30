class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
         int i=0,j=arr.size()-1;
         vector<int> ans;
    while(i<j){
        if(arr[i]+arr[j]==target){
           ans.push_back(i+1);
           ans.push_back(j+1);
        break;}
        else if(arr[i]+arr[j]<target) i++;
        else j--;
    }
    return ans;
    }
};