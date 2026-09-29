class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({tasks[i][0], tasks[i][1], i});
        sort(arr.begin(), arr.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> ans;
        long long time = 0;
        int i = 0;
        while (i < n || !pq.empty()) {
            if (pq.empty())
                time = max(time, (long long)arr[i][0]);
            while (i < n && arr[i][0] <= time) {
                pq.push({arr[i][1], arr[i][2]});
                i++;
            }
            auto cur = pq.top();
            pq.pop();
            ans.push_back(cur.second);
            time += cur.first;
        }
        return ans;
    }
};