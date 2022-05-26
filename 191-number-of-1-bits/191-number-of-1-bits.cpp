class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n){
            n = n&(n-1); //Drops LSB bit everytime
            cnt++;
        }
        
        return cnt;
    }
    //T - O(No. of set bits)
    //S - O(1)
};