//Method1
class Solution {
public:
    int mySqrt(int x) {
        if(x<0) return 0;
        int ans=0;
        for(long long i=1;i*i<=x;i++){
            ans=i;
        }
        return ans;
    }
};

//Method2
class Solution {
public:
    int mySqrt(int x) {
       if(x<2) return x;
       int l=1,h=x;
       int ans=0;
       while(l<=h){
        long long mid=l+(h-l)/2;
       if(mid==x/mid) return mid;
       else if(mid<=x/mid) {
        ans=mid;
        l=mid+1;
       }
       else{
        h=mid-1;
       }
       }
       return ans;
    }
};