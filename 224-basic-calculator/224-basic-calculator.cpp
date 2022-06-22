class Solution {
public:
    int calculate(string s) {
        
      /*Push in order [prevLevelResult, Whole sign of this level]  so that when this level end and we revert back to prevLevel(outer level), we can do prevLevelResult(outer level = Now curLevel) = prevLevelResult + sign*curLevelResult(inner level = Now prevLevel)*/
         
        int curRes = 0; //Maintains res of current bracket level
        int curNum = 0;
        int sign = 1;
        
        stack<int> st;
        for(int i = 0; i <= s.size(); i++){
            
            if(i==s.size()){
                curRes += sign*curNum;
                continue;
            }
            
            if(i < s.size() && s[i] ==' '){
                continue;
            }
                    
            if(i<s.size() && isdigit(s[i])){
                curNum = curNum*10 + (s[i]-'0');
            }else if(i < s.size() && (s[i] == '+' || s[i] == '-')){
                curRes += sign*curNum;
                curNum = 0;
                if(s[i] == '+') sign = 1;
                else sign = -1;
            }else if(s[i] == '('){ //Start a new bracket level
                st.push(curRes);
                st.push(sign);
                sign = 1;
                curRes = 0;
            }else if(s[i] == ')'){ //End the current bracket level and restart the old
                curRes += sign*curNum;
                curRes = st.top()*curRes; st.pop();
                curRes = st.top() + curRes; st.pop(); 
                curNum = 0;
            }
            
        }
        
        return curRes;
    }
    //T - O(n)
    //S - O(n)
};