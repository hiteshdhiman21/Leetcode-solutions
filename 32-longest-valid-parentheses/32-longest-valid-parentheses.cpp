class Solution {
public:
    int longestValidParentheses(string s) {
        //Intuition: While traversing the string just push all the unmatched indexes into the stack. The valid matched substrings will be between these indices.
        //Step -1. Start traversing the string. If s[i] == '(', just push this index since it is currently unmatched. If s[i] == ')', and s[st.top()] == '(', both the indices are matched, hence no need to push this and just remove the matched index. If s[st.top()] != '(', this index is also unmatched hence push it into the stack.
        //Step-2. The valid matched substrings will be between these indices present in the stack. So, while emptying the stack do ans = max(ans, end-start-1).
        //Step-3. Finally return the ans.
        
        
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
    //T - O(n)
    //S - O(n)
};