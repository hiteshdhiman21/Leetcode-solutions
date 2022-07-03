/*Very easy to implement approach*/
#define N 500

class Twitter {

private:
    vector<vector<int>> timeline;
    vector<unordered_set<int>> following; 
    
public:
    Twitter() {
        following.resize(N+1);
    }
    
    void postTweet(int userId, int tweetId) { //T - O(1)
        timeline.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) { //T - O(Total Tweets)
        vector<int> res;
        
        for(int i = (int)timeline.size()-1; i>=0; i--){
            if(timeline[i][0] == userId || following[userId].count(timeline[i][0]))
                res.push_back(timeline[i][1]);
            
            if(res.size() == 10) break;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) { //T - O(1)
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) { // T- O(1)
        following[followerId].erase(followeeId);
    }
};
//S - O(Total Tweets + Total followings)

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */