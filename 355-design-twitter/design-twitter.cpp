class Twitter {
    int timestamp = 1;
    unordered_map<int, vector<int>> mp;
    // timestamp, tweetid
    deque<pair<int,int>> tweets[501];
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_front({timestamp++, tweetId});

        if(tweets[userId].size() > 10){
            tweets[userId].pop_back();
        }
        
    }
    
    vector<int> getNewsFeed(int userId) {
        // ids allowed;
        unordered_map<int,int> toInclude;
        toInclude[userId] = 1;
        auto list = mp[userId];
        for(auto id : list){
            toInclude[id] = 1;
        }

        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        for(auto [key, val] : toInclude){
            vector<pair<int,int>> temp(tweets[key].begin(), tweets[key].end());
            for(int i =0; i<temp.size(); i++){
                pq.push(temp[i]);
            }
        }

        int count =0;
        while(!pq.empty()){
            auto [timestamp, tweetId] = pq.top();
            pq.pop();
            ans.push_back(tweetId);
            count++;
            if(count >= 10) break;
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