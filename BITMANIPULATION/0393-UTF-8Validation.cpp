class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int bytes = 0;
        for (int num : data) {
            if (bytes == 0) {
                if ((num >> 7) == 0b0)
                    bytes = 0;
                else if ((num >> 5) == 0b110)
                    bytes = 1;
                else if ((num >> 4) == 0b1110)
                    bytes = 2;
                else if ((num >> 3) == 0b11110)
                    bytes = 3;
                else
                    return false;
            } else {
                if ((num >> 6) != 0b10)
                    return false;
                bytes--;
            }
        }
        return bytes == 0;
    }
};