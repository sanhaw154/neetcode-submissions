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
        priority_queue<vector<int>> maxheap;
        if(!follower.count(userId))
        {
            follower.insert({userId,{userId}});
        }
        unordered_set<int>& followList =follower[userId]; //該userID追隨的清單
        for(auto followee : followList)
        {
            vector<pair<int,int>>& postList = postRecord[followee];
            int idx = postList.size()-1;
            if(idx >= 0)
            {
                maxheap.push({postList[idx].first,postList[idx].second,followee,idx-1}); //{time,tweetId,posterId,nextPostIdx}
            }
            
        }
        while(!maxheap.empty() && res.size() < 10 )
        {
            auto& infor = maxheap.top();
            const int& postTime = infor[0];
            const int& tweetId = infor[1];
            const int& posterId = infor[2];
            const int& next_postIdx = infor[3];
            
            if(next_postIdx >= 0)
            {   
                vector<pair<int,int>>& postList = postRecord[posterId];
                maxheap.push({postList[next_postIdx].first,postList[next_postIdx].second,posterId,next_postIdx-1});
            }
            res.push_back(tweetId);
            maxheap.pop();
        }
        time++;
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(!follower.count(followerId)) //該followerId尚未追隨過人
        {
            follower.insert({followerId,{followerId}}); 
        }
        follower[followerId].insert(followeeId);
        time++;
        return;
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId) //自己不能停追自己
        {
            follower[followerId].erase(followeeId);
        }
        time++;
        return;
    }
};
