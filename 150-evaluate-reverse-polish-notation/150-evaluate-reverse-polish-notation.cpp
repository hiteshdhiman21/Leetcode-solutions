class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(string& s: tokens){
            if(s == "/" || s == "-" || s == "+" ||s == "*"){
                int snum = st.top(); st.pop();
                int fnum = st.top(); st.pop();
                
                int res = 0;
                switch(s[0]){
                    case '+': res = fnum+snum;
                                break;
                    case '-': res = fnum-snum;
                                break;
                    case '*': res = fnum*snum;
                                break;
                    case '/': res = fnum/snum;
                                break;               
                }
                
                st.push(res);
            }else{
                st.push(stoi(s));
            }
        }
        
        return st.top();
    }
};