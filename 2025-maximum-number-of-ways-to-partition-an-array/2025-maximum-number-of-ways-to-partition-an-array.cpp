class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<long, int> suffSumCnt;
        
        long suffSum = 0;
        for(int i = n-1; i>=0; i--){
            suffSum += nums[i];
            suffSumCnt[suffSum]++;
        }
        
        long totSum = suffSum;
        int maxPartitions = 0;
        
        if(totSum%2 == 0){
            maxPartitions = suffSumCnt[totSum/2]; //1
            if(totSum == 0)
                maxPartitions--; //0
        }
    
        unordered_map<long, int> prefSumCnt;
        /*i
        /PrefSum [0...i-1] , SuffSum [i+1, n]
        [0, 1, 2, 3, 4, 5]
        [4, 0, 3, 1] // k= 0
               c*/
        long prefSum = 0;
        for(int i =0; i<n; i++){
            suffSumCnt[suffSum]--;
            
            int totSumAfterUpdate = totSum-nums[i]+k;
            if(totSumAfterUpdate%2 == 0){
                int var2 = suffSumCnt[totSumAfterUpdate/2];
                int var1 = prefSumCnt[totSumAfterUpdate/2];
                maxPartitions = max(maxPartitions, var1+var2);
            }
            
            prefSum += nums[i];
            suffSum -= nums[i];
            prefSumCnt[prefSum]++;
            
        }
        
        return maxPartitions;
        
    }
    //T - O(n)
    //S - O(n)
};