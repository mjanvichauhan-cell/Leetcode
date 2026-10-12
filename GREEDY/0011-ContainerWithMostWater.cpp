class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int left=0;
        int right=height.size()-1;
        while (left<right){
            int width = right - left;
            int length = min(height[right], height[left]);
            max_area = max(width * length, max_area);
            if (height[right]<height[left]){
                right-=1;
            }
            else{
                left+=1;
            }
        }
        return max_area;
    }
};