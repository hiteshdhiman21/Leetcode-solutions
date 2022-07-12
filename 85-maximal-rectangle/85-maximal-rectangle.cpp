class Solution {
public:
      int largestRectangleArea(vector<int>& heights) {
        
      
        int n = heights.size();
        vector<int> leftSmall(n);
        vector<int> rightSmall(n);
        
        stack<int> st;
        
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
    
    int maximalRectangle(vector<vector<char>>& matrix) {
      /*Approach: Use DP and largest rectangle in Histogram
        Step-1. For each row calculate heights vector in O(m) using DP. and Maintain res = 0.
        Step-2. Call largestHistogram() on heights vector for each row and return the update res = max(res, largestHistogram());
        Step-3. Finally return res.
        */
        int n = matrix.size(), m = matrix[0].size();
        vector<int> heights(m, 0);
        
        int res = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            
            res = max(res, largestRectangleArea(heights));
        }
        
        return res;
    }
    //T - O(n*m)
    //S - O(m)
};