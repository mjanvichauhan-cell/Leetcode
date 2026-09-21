class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
      sort(arr.begin(),arr.end());
      for(int i=0;i<arr.size();i++){
        int low=0,high=arr.size()-1;
        int target=2*arr[i];
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (arr[mid] == target) {
                    if (mid != i)
                        return true;
                    break; 
                }
                if (arr[mid] < target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
      }
      return false;
    }
};