class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
          unordered_map<int, int> rank;
        for (int i = 0; i < (int)arr2.size(); i++) rank[arr2[i]] = i;
        sort(arr1.begin(), arr1.end(), [&](int a, int b) {
            auto ia = rank.find(a);
            auto ib = rank.find(b);
            if (ia != rank.end() && ib != rank.end()) return ia->second < ib->second;
            if (ia != rank.end()) return true;
            if (ib != rank.end()) return false;
            return a < b;
        });
        return arr1;
    }
};