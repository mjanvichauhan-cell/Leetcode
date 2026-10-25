class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revGraph(n);
        vector<int> outDegree(n, 0);
        for (int i = 0; i < n; i++) {
            outDegree[i] = graph[i].size();
            for (int it : graph[i]) {
                revGraph[it].push_back(i);
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (outDegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (int prev : revGraph[node]) {
                outDegree[prev]--;
                if (outDegree[prev] == 0)
                    q.push(prev);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};