class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> output;
    stack<int> st;
    for (int i=nums2.size()-1;i>=0;i--){
        while(!st.empty() and nums2[i]>=st.top()){
            st.pop();
        }
        if(st.empty()){
        output[nums2[i]]=-1;
        }
        else {
            output[nums2[i]]=st.top();
        }
        st.push(nums2[i]);
    }
    vector<int> ans;
    for(int i=0;i<nums1.size();i++){
        ans.push_back(output[nums1[i]]);
    }
    return ans;
        
    }
};