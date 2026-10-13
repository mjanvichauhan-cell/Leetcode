class Solution {
public:
bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st){
        vis[node] = 1; 
        for(auto v : adj[node]){
            if(vis[v] == 0){
                if(dfs(v, adj, vis, st)) return true;
            }
            else if(vis[v] == 1){
                return true;
            }
        }
        vis[node] = 2;
        st.push(node);
        return false;
    }
void toporder(int src,vector<bool> &vis,stack<int> &s,vector<vector<int>>&edges){
    vis[src]=true;
    for(int i=0;i<edges.size();i++){
        int v=edges[i][0];
        int u=edges[i][1];
        if(src==u){
            if(!vis[v]){
                (toporder(v,vis,s,edges)) ;
            }
        }
    }
    s.push(src) ;
}
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &e : edges){
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(dfs(i,adj,vis,st)) return {};
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};