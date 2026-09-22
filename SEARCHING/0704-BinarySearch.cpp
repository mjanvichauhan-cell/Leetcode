//method1
class Solution {
public:
    int binearysearchrec(vector<int> &v,int tar,int lo ,int hi){
    if(lo>hi) return -1;
        int mid=lo+(hi-lo)/2;
        if(v[mid]==tar) return mid;
        if (v[mid]<tar) return binearysearchrec(v, tar,mid+1 , hi);
        else return binearysearchrec(v, tar,lo,mid-1);
    }
    
    int search(vector<int>& arr, int tar) {
        int st=0,end=arr.size()-1;
    return binearysearchrec(arr,tar,0,arr.size()-1);
        
    }
};

//Method2
class Solution {
public:
    int search(vector<int>& nums, int target) {
         int n=nums.size();
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) {
           return mid;
        }
        else if (nums[mid] < target) {
            low = mid + 1;
        }
        else {
           high = mid - 1;
        }
    }
    return -1;
    }
};