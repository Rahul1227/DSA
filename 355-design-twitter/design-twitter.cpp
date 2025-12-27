class Twitter {
    unordered_map<int, vector<int>> mp;
    vector<pair<int,int>> tweets;
    // userId, tweetId
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
        
    }
    
    vector<int> getNewsFeed(int userId) {
        // ids allowed;
        unordered_map<int,int> toInclude;
        toInclude[userId] = 1;
        auto list = mp[userId];
        for(auto id : list){
            toInclude[id] = 1;
        }
        int count = 0;
        vector<int> ans;
        for(int i = tweets.size()-1; i>=0; i--){
            auto [userId, tweetId] = tweets[i];
            if(toInclude.find(userId) != toInclude.end()){
                ans.push_back(tweetId);
                count++;
                if(count >= 10) break;
            }

        }

        return ans;
        
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].push_back(followeeId);
        
    }
    
    void unfollow(int followerId, int followeeId) {
        vector<int> &followedList = mp[followerId];
        int ind = -1;
        for(int i =0; i< followedList.size(); i++){
            if(followedList[i] == followeeId){
                ind = i;
            }

            
        }
        if(ind != -1){
            followedList.erase(followedList.begin()+ind);
        }
        
        
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