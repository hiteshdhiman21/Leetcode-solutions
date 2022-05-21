class Solution {
public:
    char exactMatch(char& ch){
        if(ch == ')') return '(';
        else if(ch == '}') return '{';
        else if(ch == ']') return '[';
        return '0';
    }
    
    //for ch in s:
    //  if(ch is opening parenthesis) push into stack
    //  else if(st is not empty and st.top() == exactMatch(ch)) pop
    //  else return false;  //Because there is no opening for this closing parenthesis
    
    //Finally if(st.size() == 0) return true
    //        else return false //As there is no closing parenthesis for parenthesis pushed into stack
    
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