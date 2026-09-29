class Twitter {
    int timer;
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int,int>>> tweets;
public:
    Twitter() {
        timer = 0;
    }
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer--, tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        followMap[userId].insert(userId);
        for (int user : followMap[userId]) {
            if (tweets[user].empty()) continue;
            int idx = tweets[user].size() - 1;
            pq.push({tweets[user][idx].first, tweets[user][idx].second, user, idx});
        }
        vector<int> ans;
        while (!pq.empty() && ans.size() < 10) {
            auto cur = pq.top();
            pq.pop();
            int time = cur[0];
            int tweetId = cur[1];
            int user = cur[2];
            int idx = cur[3];
            ans.push_back(tweetId);
            if (idx > 0) {
                idx--;
                pq.push({tweets[user][idx].first, tweets[user][idx].second, user, idx});
            }
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followMap[followerId].erase(followeeId);
    }
};
/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */