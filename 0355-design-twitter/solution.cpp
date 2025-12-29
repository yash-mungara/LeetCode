class Twitter {

    int time;

    unordered_map<int, unordered_set<int>> follows;
    //  userID -> follower ID set;

    unordered_map<int,vector<pair<int,int>>> tweets;
    // userID -> pair(time,tweetID) list;

public:    
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
        follows[userId].insert(userId);     // follow itself;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        if (!follows.count(userId)) return res;

         // max heap: {time, tweetId, userId, index}
        priority_queue<vector<int>> pq;

        for (int followee : follows[userId]) {
            auto &t = tweets[followee];
            if (!t.empty()) {
                int idx = t.size() - 1;
                pq.push({t[idx].first, t[idx].second, followee, idx});
            }
        }

        while (!pq.empty() && res.size() < 10) {
            auto top = pq.top(); pq.pop();
            res.push_back(top[1]);

            int user = top[2];
            int idx = top[3] - 1;
            if (idx >= 0) {
                pq.push({tweets[user][idx].first,
                         tweets[user][idx].second,
                         user, idx});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);  
        follows[followerId].insert(followerId);  
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId) follows[followerId].erase(followeeId);
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
