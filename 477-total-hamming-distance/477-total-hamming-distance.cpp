class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        
        for(int b=0; b<32; b++){
            int setCnt = 0;
            for(int x: nums)
                if(x&(1<<b))
                    setCnt++;
            
            res += setCnt*(n-setCnt);
        }
        
        return res;
    }
    //T - O(32n)
    //S - O(1)
};