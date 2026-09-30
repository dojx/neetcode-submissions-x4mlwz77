class Twitter {
private:
    unordered_map<int, set<int>> followers; // userID: list of following
    stack<pair<int, int>> tweets;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        if (!followers.contains(userId))
            followers[userId].insert(userId);
        tweets.push({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        stack<pair<int, int>> tmp = tweets;
        vector<int> res;
        int n = 10;
        while (n && !tmp.empty()) {
            auto tweet = tmp.top(); tmp.pop();
            if (followers[userId].count(tweet.first)) {
                res.push_back(tweet.second);
                n--;
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
