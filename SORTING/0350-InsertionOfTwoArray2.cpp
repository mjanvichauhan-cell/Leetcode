class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
     int n1=nums1.size();
     int n2=nums2.size();
    unordered_map<int,int>st;
      vector<int>ans;
      for(int i=0;i<n1;i++){
        st[nums1[i]]++;
      }
      for(int j=0;j<n2;j++){
        if(st.find(nums2[j])!=st.end() && st[nums2[j]]>0){
            ans.push_back(nums2[j]);
            st[nums2[j]]--;
        }
      }
    return ans;
    }
};