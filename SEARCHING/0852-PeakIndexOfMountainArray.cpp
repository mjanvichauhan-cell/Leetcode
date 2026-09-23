class Solution {
public:
int peakIndexInMountainArray(vector<int> &v){
    int lo=1;
    int hi=v.size()-1;
    int ans =-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(v[mid]>v[mid-1]) {
            ans=max(ans,mid);
            lo= mid+1;
        }
        else hi=mid-1;
    }
    return ans;
}
};