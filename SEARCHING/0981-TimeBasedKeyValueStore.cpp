class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> m;
    TimeMap() {   
    }
    void set(string key, string value, int timestamp) {
        m[key].push_back({value, timestamp});
    }
    string get(string key, int timestamp) {
        if (m.find(key) == m.end()) return "";
        vector<pair<string, int>> &v = m[key];
        int n = v.size(), l = 0, h = n - 1, res = -1;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            if (v[mid].second <= timestamp) {
                res = mid;
                l = mid + 1;
            } else  {
                h = mid - 1;
            }
        }
        return res == -1 ? "" : v[res].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */