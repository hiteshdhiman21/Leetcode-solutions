class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xr = 0;
        for(int x: nums) xr = xr^x;
        return xr;
    }
    //T - O(n)
    //S - O(1)
};