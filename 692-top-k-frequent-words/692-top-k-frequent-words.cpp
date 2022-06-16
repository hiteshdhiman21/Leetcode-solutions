class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for(auto& str:words)
            freq[str]++;
        
        vector<vector<string>> freqBucket(words.size()+1);
        for(auto &__:freq){
            freqBucket[__.second].push_back(__.first);
        }
        
        vector<string> ans;
        for(int f = words.size(); f>=1 && ans.size() < k; f--){
            sort(freqBucket[f].begin(), freqBucket[f].end());
            for(auto &str: freqBucket[f]){
               ans.push_back(str);
                if(ans.size() == k) break;
            }
                
        }
        return ans;
    }
    //T - O(nlogk)
    //S - O(n)
};