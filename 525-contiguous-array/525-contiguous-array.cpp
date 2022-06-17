class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      /*Similar to largest subarray with zero sum(Exact same trick)
        Step-1. Iterate through whole array and add '1' to sum for '1' and '-1' to sum for '0'.
        Step-2. Now at any ind if sum equal to sum has already occured at some prevInd. it means the subsarray[prevInd+1 ... ind] contains equal no. of zeroes and ones.
        Step-3. Return the max length of all those subarrays.=
      */  
        
        unordered_map<int, int> firstIndForSum;
        
        firstIndForSum[0] = -1;
        
        int maxLength = 0;
        
        int sum = 0;
        
        for(int i= 0; i < nums.size(); i++){
            sum += nums[i]==1?1:-1;
            
            if(firstIndForSum.count(sum) == 0){
                firstIndForSum[sum] = i;
            }else{
                maxLength = max(maxLength, i-firstIndForSum[sum]);
            }
        }
            
        return maxLength;
    }
};