class Solution {
public:
    bool isPerfectSquare(int num) {
        int st=1,end=num,ans=-1;
        if(num==0 || num==1) return true;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(mid==num/mid && num%mid==0) return true;
            else if(mid<num/mid){
                 ans=mid;
                 st=mid+1;
                 }
            else end=mid-1;
        }
        return false;
    }
};