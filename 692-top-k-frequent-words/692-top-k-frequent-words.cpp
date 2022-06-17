class comp{
    public:
    bool operator()(pair<string, int> f, pair<string, int> s){
        //For min heap second have to be min
        if(f.second > s.second) return true;
        else if(f.second < s.second) return false;
        else return f.first < s.first;
        //Min freq will be at top and for same freq lexiographic bigger will be at top
    }
};

class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for(auto& str:words)
            freq[str]++;
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, comp> pq; 
        for(auto &__:freq){
            if(pq.size() < k)
            pq.push(__);
            else if(__.second > pq.top().second || (__.second == pq.top().second && __.first < pq.top().first)){
                pq.pop();
                pq.push(__);
            }
        }
        
        vector<string> res(k);
        while(!pq.empty()){
            res[--k] = pq.top().first;
            pq.pop();
        }
        
        return res;
    }
    //T - O(nlogk)
    //S - O(n)
};