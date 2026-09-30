class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
         int st=0,end=arr.size()-1,ans=-1;
        while (st < end) {
          int mid = st + (end - st) / 2;
            if (arr[mid] < arr[mid + 1])
             st = mid + 1;     
            else
             end = mid;         
     }
    int peak = st;
    if (peak == 0 || peak == arr.size() - 1)
    return false;

    for (int i = 0; i < peak; i++)
    if (arr[i] >= arr[i + 1]) return false;
    for (int i = peak; i < arr.size() - 1; i++)
    if (arr[i] <= arr[i + 1]) return false;
    return true;
        return false;
    }
};