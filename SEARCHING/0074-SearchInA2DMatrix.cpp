class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int tar) {
    int n=v.size(),m=v[0].size(),lo=0,hi=n*m-1;
    int ans =-1;
    while(lo<=hi){
       int mid=lo+(hi-lo)/2,x=mid/m,y=mid%m;
       if(v[x][y]==tar) return true;
       else if(v[x][y]<tar) lo=mid+1;
       else hi=mid-1;
    }
    return false;
    }
};