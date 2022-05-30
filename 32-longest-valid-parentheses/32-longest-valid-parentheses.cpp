class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for(int i = 0; i <s.size(); i++){
            if(s[i] == '(') st.push(i);
            else{
                if(s[i] == ')' && st.size()>1 && s[st.top()] == '('){
                    st.pop();
                }else{
                    st.push(i);
                }
            }
        }
        
        st.push(s.size());
        int end = st.top(); st.pop();
        
        
        while(!st.empty()){
            int start = st.top(); st.pop();
            ans = max(ans, end-start-1);
            end=start;
        }
        
        return ans;
    }
};