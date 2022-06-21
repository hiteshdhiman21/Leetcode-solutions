class Solution {
public:
    int calculate(string s) {
      /*Stack - No BODMAS. Just perform Multiplication and division first according to their occurences at last perform addition and subtraction.
        Storing the sign before the curNum in curOp
        Step-1. Iterate over all the characters in s.
        Step-2. If character is whitespace, just continue.
        Step-3. If character is digit, Just add the digit into curNum.
        Step-4. If it is the end of string or charater is some operator. Just perform the operation accoring to curOp.
                If curOp == '+' or '-' just push the curNum with the appropriate sign into the stack(we will perform these operations later). Else if curOp == '*' or '/' Just perform the operation between the st.top() and curNum and push it into the stack after popping the first operand from stack. And for making the next number update the curNum = 0 and curOp = current character sign.*/
        
        
        int curNum = 0;
        int sign = 1;
        stack<int> st;
        
        char curOp = '+';
        
        for(int i = 0; i <= s.size(); i++){
            
            if(i<s.size() && s[i] == ' ') continue;
            
            if(i < s.size() && s[i] >= '0' && s[i] <= '9'){
                curNum = curNum*10+(s[i]-'0');
                continue;
            }
               
            if(curOp == '+') st.push(curNum);
            else if(curOp == '-') st.push(-curNum);
            else if(curOp == '*'){
                int firstNum = st.top(); st.pop();
                st.push(firstNum * curNum);
            }else{
                int firstNum = st.top(); st.pop();
                st.push(firstNum / curNum);
            } 
               
            curNum = 0;
               
            if(i==s.size()) continue;
            else if(s[i] == '+') curOp = '+';
            else if(s[i] == '-') curOp = '-';
            else if(s[i] == '*') curOp = '*';
            else curOp = '/';
        }
        
        int ans = 0;
        while(!st.empty()){
            ans += st.top(); st.pop();
        }
        
        return ans;
    }
};
