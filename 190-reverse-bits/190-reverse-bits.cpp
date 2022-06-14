class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //Common bit manipulation approach
        uint32_t res = 0;
        for(int i = 0; i<=31; i++){
            if((n>>i)&1) res = res|(1<<(31-i));
        }
        return res;
    }
    //T - O(32)
    //S - O(1)
};