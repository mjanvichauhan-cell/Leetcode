class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1,water=0,ans=0;
        int maxleft=-1,maxright=-1;
        while(l<r){
            maxleft=max(maxleft,height[l]);
            maxright=max(maxright,height[r]);
            if(maxleft<=maxright){
              water=maxleft-height[l];
              if(water>0) ans+=water;
              l++;  
            }
            else{
              water=maxright-height[r];
              if(water>0) ans+=water;
              r--;
            }
        }
        return ans;
    }
};