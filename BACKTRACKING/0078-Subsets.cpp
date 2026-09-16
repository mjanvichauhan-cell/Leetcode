//Method1
class Solution {
public:
    void getallsubsets(vector<int> &nums,vector<int> &ans,int i,vector<vector<int>>& allsubsets){
    if(i==nums.size()){
        allsubsets.push_back({ans});
        return ;
    }
    ans.push_back(nums[i]);
    getallsubsets(nums,ans,i+1,allsubsets);
    ans.pop_back();
    getallsubsets(nums,ans,i+1,allsubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allsubsets;
        vector<int> ans;
        getallsubsets(nums,ans,0,allsubsets);
        return allsubsets;     
    }
};

//Method2
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<(1<<n);i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};