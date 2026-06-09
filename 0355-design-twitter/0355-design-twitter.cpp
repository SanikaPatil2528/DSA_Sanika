class Twitter {
private:
    // stores tweets as {userId,{timestamp,tweetId}}
    unordered_map<int,vector<pair<int,int>>> tweets;
    // stores set of followees for user
    // {follower,followee}
    unordered_map<int,unordered_set<int>> following;
    // global time counter to sort tweets
    int time;
public:
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        // min heap to store tweets based on timestamp
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;

        // insert user's own tweets
        for(auto &t:tweets[userId]){
            pq.push(t);
            if(pq.size()>10) pq.pop(); //removes oldest tweet
        }
        // insert tweets from users being followed by userId
        for(auto followee:following[userId]){
            for(auto &t:tweets[followee]){
                pq.push(t);
                if(pq.size()>10) pq.pop();
            }
        }
        // extract tweets from heap in reverse order
        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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