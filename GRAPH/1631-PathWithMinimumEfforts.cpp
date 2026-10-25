class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));
        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        effort[0][0] = 0;
        pq.push({0,{0,0}});
        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r==m-1 && c==n-1)
                return diff;
            for(int k=0;k<4;k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr>=0 && nc>=0 && nr<m && nc<n){
                    int newEffort = max(diff,abs(heights[nr][nc]-heights[r][c]) );
                    if(newEffort < effort[nr][nc]){
                        effort[nr][nc] = newEffort;
                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};