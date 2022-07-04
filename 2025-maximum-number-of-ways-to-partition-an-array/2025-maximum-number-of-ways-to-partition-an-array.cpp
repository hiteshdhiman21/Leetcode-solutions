class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        long totSum = 0;
        unordered_map<long, int> suffSumCnt, prefSumCnt;
        for(int i = n-1; i >= 0; i--){
            totSum += nums[i];
            suffSumCnt[totSum]++;
        }
        
        int res = 0;
        if(totSum%2 == 0){
            res = suffSumCnt[totSum/2];
            cout << res << " "<< nums[0] << " " << totSum/2 << endl;
            if(totSum == 0)
                res--;
        }
        
        long suffSum = totSum;
        long prefSum = 0;
         
        for(int i = 0; i<n; i++){
            long totSumAfterUpdate = totSum-nums[i]+k;
            suffSumCnt[suffSum]--;
            if(totSumAfterUpdate%2 == 0){
                int part2 = suffSumCnt[totSumAfterUpdate/2];
                int part1 = prefSumCnt[totSumAfterUpdate/2]; //No need of Now variable
                res = max(res, part1+part2);
            }
            
            prefSum += nums[i];
            prefSumCnt[prefSum]++;
            suffSum -= nums[i];
        }
        
        return res;
    }
    //T - O(n)
    //S - O(n)
};