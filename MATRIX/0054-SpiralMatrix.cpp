class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size(),minr=0,maxr=n-1,minc=0,maxc=m-1,tne=n*m,count=0;
        vector<int> ans;
        while(count<tne){
        for(int j=minc;j<=maxc;j++){
            ans.push_back(a[minr][j]);
            count++;
        }
        minr++;
        if(count>=tne) break;
        for(int i=minr;i<=maxr;i++){
            ans.push_back(a[i][maxc]);
            count++;
        }
        maxc--;
        if(count>=tne) break;
        for(int j=maxc;j>=minc;j--){
            ans.push_back(a[maxr][j]);
            count++;
        }
        maxr--;
        if(count>=tne) break;
        for(int i=maxr;i>=minr;i--){
            ans.push_back(a[i][minc]);
            count++;
        }
        minc++;
        if(count>=tne) break;
   }  
   return ans;
    }
};