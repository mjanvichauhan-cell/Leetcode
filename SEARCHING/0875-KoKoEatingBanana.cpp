class Solution {
public:
    bool canEat(vector<int>& piles, int h, int k){
    long long hours = 0;
    for(int x : piles){
        hours += (x + k - 1) / k;
    }
    return hours <= h;
}
int minEatingSpeed(vector<int>& piles, int h){
    int lo = 1, hi = 0;
    for(int x : piles) hi = max(hi, x);
    int ans = hi;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(canEat(piles, h, mid)){
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}
};