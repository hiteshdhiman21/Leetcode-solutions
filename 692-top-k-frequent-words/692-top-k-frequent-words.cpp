class comp{
    public:
    bool operator()(pair<string, int> f, pair<string, int> s){
        if(f.second < s.second) return true;
        else if(f.second > s.second) return false;
        else return f.first > s.first;
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
            pq.push(__);
        }
        
        vector<string> res;
        while(!pq.empty()){
            res.push_back(pq.top().first);
            pq.pop();
            
            if(res.size() == k)
                break;
        }
        
        return res;
    }
    //T - O(nlogk)
    //S - O(n)
};