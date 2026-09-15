class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string target = to_string(n);
        sort(target.begin(), target.end());

        for (int i = 0; i < 31; i++) {
            int power = 1 << i;
            string s = to_string(power);
            sort(s.begin(), s.end());
            if (s == target)
                return true;
        }

        return false;
    }
};