class Solution {
public:
    bool isvalid(vector<vector<int>> &grid,int r,int c,int n,int expVal){
    if(r<0 or c<0 or r>=n or c>=n or grid[r][c]!= expVal) return false;
    if(expVal==n*n-1) return true;
    int ans1=isvalid(grid,r-2,c+1,n,expVal+1);
    int ans2=isvalid(grid,r-1,c+2,n,expVal+1);
    int ans3=isvalid(grid,r+1,c+2,n,expVal+1);
    int ans4=isvalid(grid,r+2,c+1,n,expVal+1);
    int ans5=isvalid(grid,r+2,c-1,n,expVal+1);
    int ans6=isvalid(grid,r+1,c-2,n,expVal+1);
    int ans7=isvalid(grid,r-1,c-2,n,expVal+1);
    int ans8=isvalid(grid,r-2,c-1,n,expVal+1);
    return ans1 or ans2 or ans3 or ans4 or ans5 or ans6 or ans7 or ans8;
}

    bool checkValidGrid(vector<vector<int>>& grid) {
            return isvalid(grid,0,0,grid.size(),0);
        
    }
};