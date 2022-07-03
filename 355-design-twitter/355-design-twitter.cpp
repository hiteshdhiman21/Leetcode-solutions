using minHeap = priority_queue<int, vector<int>, greater<int>>; 
#define N 500

class Twitter {

private:
    vector<vector<int>> timeline;
    vector<set<int>> following; 
    
public:
    Twitter() {
        following.resize(N+1);
    }
    
    void postTweet(int userId, int tweetId) {
        timeline.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        
        for(int i = (int)timeline.size()-1; i>=0; i--){
            if(timeline[i][0] == userId || following[userId].count(timeline[i][0]))
                res.push_back(timeline[i][1]);
            
            if(res.size() == 10) break;
        }
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