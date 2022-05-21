class Solution {
public:
    char exactMatch(char& ch){
        if(ch == ')') return '(';
        else if(ch == '}') return '{';
        else if(ch == ']') return '[';
        return '0';
    }
    
    bool isValid(string s) {
        stack<int> st;
        for(char ch:s){
            if(ch == '(' || ch == '{' || ch == '[') st.push(ch);
            else if(!st.empty() && exactMatch(ch) == st.top()) st.pop();
            else return false;
        }
        if(st.size()==0) return true;
        else return false;
    }
    //T - O(n)
    //S - O(1);
};