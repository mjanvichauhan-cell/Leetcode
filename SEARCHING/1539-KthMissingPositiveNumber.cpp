class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       int st=0,end=arr.size()-1,ans=arr.size();
       while(st<=end){
        int mid=st+(end-st)/2;
        if(arr[mid]-mid-1>=k){
            ans=mid;
           end=mid-1;
        }
        else st=mid+1;
       }
       return ans+k;
    }
};