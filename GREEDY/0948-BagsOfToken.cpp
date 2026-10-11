class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int left = 0;
        int right = tokens.size() - 1;
        int score = 0;
        int ans = 0;
        while (left <= right) {
            if (power >= tokens[left]) {
                power -= tokens[left];
                left++;
                score++;
                ans = max(ans, score);
            }
            else if (score > 0) {
                power += tokens[right];
                right--;
                score--;
            }
            else {
                break;
            }
        }
        return ans;
    }
};