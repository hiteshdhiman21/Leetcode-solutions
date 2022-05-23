class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSmall(n);
        vector<int> rightSmall(n);
        
        stack<pair<int, int>> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top().first >= heights[i]){
                st.pop();
            }
            
            if(st.empty()) leftSmall[i] = -1;
            else{
                leftSmall[i] = st.top().second;
            }
            
            st.push(make_pair(heights[i], i));
        }
        
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top().first >= heights[i]){
                st.pop();
            }
            
            if(st.empty()) rightSmall[i] = n;
            else{
                rightSmall[i] = st.top().second;
            }
            
            st.push(make_pair(heights[i], i));
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