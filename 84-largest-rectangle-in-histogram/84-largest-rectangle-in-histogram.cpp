class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        //Intuition: Compute the left and right border for each index upto which the height is atleast heights[ind] to calculate width[ind], otherwise the rectangle with heights[ind] can't be formed after those indexes. And for each do ans = max(ans, heights[ind]*width[ind])
        //Step-1. First we compute leftSmall and rightSmall height indexes for each height index using PSE, NSE.
        //Step-2. Then we iterate over the heights array and for each index computes area = heights[ind]*width[ind], where width[ind] = rightSmall[ind]-leftSmall[ind]-1.
        
        int n = heights.size();
        vector<int> leftSmall(n);
        vector<int> rightSmall(n);
        
        stack<int> st;
        //Using Next Greater element finding technique to find PSE and NSE for each index.
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            
            if(st.empty()) leftSmall[i] = -1;
            else{
                leftSmall[i] = st.top();
            }
            
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            
            if(st.empty()) rightSmall[i] = n;
            else{
                rightSmall[i] = st.top();
            }
            
            st.push(i);
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            int width = rightSmall[i]-leftSmall[i]-1;
            ans = max(ans, heights[i]*width);
        }
        
        return ans;
        //T - 5n    (3 Passes)
        //S - O(2n)
    }
};