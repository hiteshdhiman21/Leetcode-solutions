class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //Approach: Bucket sort
        //Step-1. We will make a bucket for each freq. Where Bucket[freq] will store all those elements having frequency = freq.
        //Step-2. First convert the given array into a frequency based hashmap. And then travel freqMap to push elements into the bucket of corresponding frequency.
        //Step-3. Now visit all the freq buckets, from the highest freq till the lowest and keep adding elements into the ans vector from the buckets until the ans vector reaches size k.
        
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int x:nums) freq[x]++;
        
        vector<vector<int>> bucketOfFreq(n+1);
        for(auto __:freq){
            int x = __.first, cnt = __.second;
            bucketOfFreq[cnt].push_back(x);
        }
        
        vector<int> ans;
        for(int Freq = n; Freq>=1; Freq--){
            for(int x:bucketOfFreq[Freq]) ans.push_back(x);
            if(ans.size() == k) break;
        }
             
        return ans;
    }
    //T - O(n)
    //S - O(n)
};