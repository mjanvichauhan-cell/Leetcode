class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants,
                                  int veganFriendly,
                                  int maxPrice,
                                  int maxDistance) {
        vector<vector<int>> valid;
        for (auto &r : restaurants) {
            int id = r[0];
            int rating = r[1];
            int vegan = r[2];
            int price = r[3];
            int distance = r[4];
            if ((veganFriendly == 0 || vegan == 1) &&
                price <= maxPrice &&
                distance <= maxDistance) {
                valid.push_back(r);
            }
        }
        sort(valid.begin(), valid.end(), [](auto &a, auto &b) {
            if (a[1] != b[1])
                return a[1] > b[1];  
            return a[0] > b[0];     
        });
        vector<int> ans;
        for (auto &r : valid)
            ans.push_back(r[0]);
        return ans;
    }
};