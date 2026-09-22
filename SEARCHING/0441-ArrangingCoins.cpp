class Solution {
public:
    int arrangeCoins(int sum) {
        long long left = 1;
        long long right = sum;
        long long mid;
        int ans =0;
        while(left <= right){
            mid = left-(left-right)/2;
            if((mid*(mid+1)/2) <= sum){
                ans = mid;
                left= mid+1;
            }else{
                right = mid-1;
            }
        }
        return ans;
    }
};