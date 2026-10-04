class Solution {
public:
     bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
    string sortVowels(string s) {
        vector<char> vowels;
        for (char ch : s) {
            if (isVowel(ch)) {
                vowels.push_back(ch);
            }
        }
        sort(vowels.begin(), vowels.end());
        int index = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[index++];
            }
        }
        return s;
    }
};