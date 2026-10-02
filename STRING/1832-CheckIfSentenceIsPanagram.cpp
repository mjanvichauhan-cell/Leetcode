class Solution {
public:
    bool checkIfPangram(string s) {
         int freq[26] = {0};
    for (char ch : s) {
        if (ch >= 'A' && ch <= 'Z')
            ch = ch + 32;
        if (ch >= 'a' && ch <= 'z')
            freq[ch - 'a'] = 1;
    }
    for (int i = 0; i < 26; i++) {
        if (freq[i] == 0)
            return false;
    }
    return true;

    }
};