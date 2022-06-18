class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> sumFreq;
        sumFreq[0]++;
        
        int cnt = 0;
        
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sumFreq.count(sum-k))
                cnt += sumFreq[sum-k];
            
            sumFreq[sum]++;
        }
        
        return cnt;
    }
    //T - O(n)
    //S - O(n)
};