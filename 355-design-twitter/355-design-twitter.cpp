using minHeap = priority_queue<int, vector<int>, greater<int>>; 
#define N 500

class Twitter {

private:
    int cntr;
    unordered_map<int, int> mp; //To map cntr-tweetid
    unordered_map<int, set<int>> setFor; //To map each userID with Feed
    vector<set<int>> followedBy;
    unordered_map<int, int> tweetVsUser;
    unordered_map<int, set<int>> userVsTweet;
    
public:
    Twitter() {
        cntr = 0;
        followedBy.resize(N+1);
    }
    
    void postTweet(int userId, int tweetId) {
        followedBy[userId].insert(userId);
        for(int x: followedBy[userId]){
            setFor[x].insert(cntr);
            mp[cntr] = tweetId;    
        }
        
        tweetVsUser[tweetId] = userId;
        userVsTweet[userId].insert(cntr);
        cntr++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        for(auto it = setFor[userId].rbegin(); it != setFor[userId].rend(); it++){
            int cntr = *it;
            res.push_back(mp[cntr]);
            
            if(res.size() == 10) break;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followedBy[followeeId].insert(followerId);
        
        for(int tweetCntr: userVsTweet[followeeId]){
            setFor[followerId].insert(tweetCntr);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followedBy[followeeId].erase(followerId);
        
        vector<int> tweetsFromFolloweeId;
        for(int tweetCntr: setFor[followerId]){
            if(tweetVsUser[mp[tweetCntr]] == followeeId){
                setFor[followerId].erase(tweetCntr);
            }
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