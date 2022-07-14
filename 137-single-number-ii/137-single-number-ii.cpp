class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int b=0; b<32; b++){
            int cnt = 0;
            for(int x: nums){
                if(x&(1<<b)) cnt++;
            }
            
            if(cnt%3 != 0) res = res|(1<<b);
        }
        
        return res;
    }
    //T - O(32n)
    //S - O(1)
};