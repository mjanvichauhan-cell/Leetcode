class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, int> level;
    void dfs(string word, string beginWord,
             vector<string>& path) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }
        int currLevel = level[word];
        for (int i = 0; i < word.size(); i++) {
            string temp = word;
            char original = temp[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                temp[i] = ch;
                if (level.count(temp) &&
                    level[temp] == currLevel - 1) {
                    path.push_back(temp);
                    dfs(temp, beginWord, path);
                    path.pop_back();
                }
            }
            temp[i] = original;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord,vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (!st.count(endWord))
            return {};
        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 0;
        st.erase(beginWord);
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int currLevel = level[word];
            for (int i = 0; i < word.size(); i++) {
                string temp = word;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;
                    if (st.count(temp)) {
                        level[temp] = currLevel + 1;
                        q.push(temp);
                        st.erase(temp);
                    }
                }
            }
        }
        if (!level.count(endWord))
            return {};
        vector<string> path;
        path.push_back(endWord);
        dfs(endWord, beginWord, path);
        return ans;
    }
};