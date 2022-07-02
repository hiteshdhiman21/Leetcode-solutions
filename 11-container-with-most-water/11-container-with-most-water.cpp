class Solution {
public:
    int maxArea(vector<int>& height) {
      /*Approach: 2-pointers
        Check for cases: [4, 20, 2, 4] and [5, 20, 5, 15, 4, 5]*/
        
        int l = 0, r = height.size()-1;
        int res = 0;
        while(l<r){
            res = max((r-l)*min(height[l], height[r]), res);
            if(height[l] < height[r])
                l++;
            else
                r--;
        }
        
        return res;
    }
    //T - O(n)
    //S - O(1)
};