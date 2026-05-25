class Twitter {
    int time = 0;
    unordered_map<int,vector<pair<int,int>>> postRecord;
    unordered_map<int,unordered_set<int>> follower;
    
public:
    Twitter() {
       
    }
    
    void postTweet(int userId, int tweetId) {
        vector<pair<int,int>>& postList = postRecord[userId];
        postList.push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int,int>> maxheap;
        if(!follower.count(userId))
        {
            follower.insert({userId,{userId}});
        }
        unordered_set<int>& followList =follower[userId];
        for(auto followee : followList)
        {
            vector<pair<int,int>>& postList = postRecord[followee];
            for(auto& [postTime,tweetId] : postList)
            {
                maxheap.push({postTime,tweetId});
            }
        }
        while(!maxheap.empty() && res.size() < 10 )
        {
            auto [postTime,tweetId] = maxheap.top();
            res.push_back(tweetId);
            maxheap.pop();
        }
        time++;
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(!follower.count(followerId))
        {
            follower.insert({followerId,{followerId}});
        }
        follower[followerId].insert(followeeId);
        time++;
        return;
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId)
        {
            follower[followerId].erase(followeeId);
        }
        time++;
        return;
    }
};
