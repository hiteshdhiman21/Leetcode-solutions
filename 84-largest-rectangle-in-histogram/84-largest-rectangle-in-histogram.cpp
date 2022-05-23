class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        //Its a over-optimised solution with decreasing constant factors in complexity
        //In this approach we are calculating ans for the elements in stack which are to be removed. i.e. for which the right small is ind and left small is the index just below it in the stack.
        //Hence we iterate till index n to remove all the elements.
        //Intuition: Compute the left and right border for each index upto which the height is atleast heights[ind] to calculate width[ind], otherwise the rectangle with heights[ind] can't be formed after those indexes. And for each do ans = max(ans, heights[ind]*width[ind])
        //Step-1. First we compute leftSmall and rightSmall height indexes for each height index using PSE, NSE.
        //Step-2. Then we iterate over the heights array and for each index computes area = heights[ind]*width[ind], where width[ind] = rightSmall[ind]-leftSmall[ind]-1.
        
        int n = heights.size();
        
        int ans = 0;
        stack<int> st;
        //Using Next Greater element finding technique to find PSE and NSE for each index.
        
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n || heights[st.top()] >= heights[i])){
                int height = heights[st.top()]; st.pop();
                int width = i;
                if(!st.empty()) width = i - st.top()-1;
                ans = max(ans, height*width);
            }
            
            st.push(i);
        }
        return ans;
        
        //T - 2n   (1-pass)
        //S - O(n)  (1-stack only)
    }
};