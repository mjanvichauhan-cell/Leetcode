class Solution {
public:
    std::vector<int> fallingSquares(std::vector<std::vector<int>>& positions) {
        int n = positions.size();
        std::vector<int> heights(n);
        std::vector<int> ans;
        int current_max = 0;

        for (int i = 0; i < n; ++i) {
            int left1 = positions[i][0];
            int side1 = positions[i][1];
            int right1 = left1 + side1;
            int base_height = 0;
            for (int j = 0; j < i; ++j) {
                int left2 = positions[j][0];
                int side2 = positions[j][1];
                int right2 = left2 + side2;
                if (left1 < right2 && left2 < right1) {
                    base_height = std::max(base_height, heights[j]);
                }
            }
            heights[i] = base_height + side1;
            current_max = std::max(current_max, heights[i]);
            ans.push_back(current_max);
        }
        return ans;
    }
};