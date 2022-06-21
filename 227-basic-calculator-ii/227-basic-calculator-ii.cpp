class Solution {
public:
    int calculate(string s) {
        int curNum = 0;
        int sign = 1;
        stack<int> st;
        
        char op = '+';
        
        for(int i = 0; i <= s.size(); i++){
            
            if(i<s.size() && s[i] == ' ') continue;
            
            if(i < s.size() && s[i] >= '0' && s[i] <= '9'){
                curNum = curNum*10+(s[i]-'0');
                continue;
            }
               
            if(op == '+') st.push(curNum);
            else if(op == '-') st.push(-curNum);
            else if(op == '*'){
                int firstNum = st.top(); st.pop();
                st.push(firstNum * curNum);
            }else{
                int firstNum = st.top(); st.pop();
                st.push(firstNum / curNum);
            } 
               
            curNum = 0;
               
            if(i==s.size()) continue;
            else if(s[i] == '+') op = '+';
            else if(s[i] == '-') op = '-';
            else if(s[i] == '*') op = '*';
            else op = '/';
        }
        
        int ans = 0;
        while(!st.empty()){
            ans += st.top(); st.pop();
        }
        
        return ans;
    }
};
