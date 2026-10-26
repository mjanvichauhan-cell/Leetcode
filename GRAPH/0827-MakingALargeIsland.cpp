class DisjointSet{
public:
    vector<int> parent,size;

    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++)
            parent[i]=i;
    }

    int findUPar(int node){
        if(parent[node]==node) return node;
        return parent[node]=findUPar(parent[node]);
    }

    void unionBySize(int u,int v){
        u=findUPar(u);
        v=findUPar(v);
        if(u==v) return;
        if(size[u]<size[v]){
            parent[u]=v;
            size[v]+=size[u];
        }
        else{
            parent[v]=u;
            size[u]+=size[v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==0) continue;
                for(int k=0;k<4;k++){
                    int nr=r+dr[k];
                    int nc=c+dc[k];
                    if(nr>=0 && nc>=0 && nr<n && nc<n
                       && grid[nr][nc]==1){
                        ds.unionBySize(r*n+c,nr*n+nc);
                    }
                }
            }
        }

        int ans=0;
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]==1) continue;
                set<int> st;
                for(int k=0;k<4;k++){
                    int nr=r+dr[k];
                    int nc=c+dc[k];
                    if(nr>=0 && nc>=0 && nr<n && nc<n
                       && grid[nr][nc]==1){
                        st.insert(ds.findUPar(nr*n+nc));
                    }
                }
                int total=1;
                for(auto parent:st)
                    total+=ds.size[parent];
                ans=max(ans,total);
            }
        }
        for(int i=0;i<n*n;i++){
            ans=max(ans,ds.size[ds.findUPar(i)]);
        }
        return ans;
    }
};