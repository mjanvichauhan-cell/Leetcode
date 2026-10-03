class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        stringstream ss(s);
        vector<string> words;
        string word;
        while(ss >> word)
            words.push_back(word);
        if(pattern.size() != words.size())
            return false;
        for(int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            if(mp1.count(c) && mp1[c] != words[i])
                return false;
            if(mp2.count(words[i]) && mp2[words[i]] != c)
                return false;
            mp1[c] = words[i];
            mp2[words[i]] = c;
        }
        return true;
    }
};