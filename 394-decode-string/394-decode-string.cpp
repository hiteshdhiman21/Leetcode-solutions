class Solution {
public:
        
    string decodeString(string str) {
        
        stack<char> st;
        for(char ch: str){
            if(ch != ']'){
                st.push(ch);
            }else{
                
                string s;
                while(st.top() != '['){
                    s += st.top(); st.pop();
                }
                
                st.pop(); //Popping '['
                
                string kStr;
                while(!st.empty() && isdigit(st.top())){
                    kStr += st.top(); st.pop();
                }
                
                reverse(s.begin(), s.end());
                reverse(kStr.begin(), kStr.end());
                
                int k = stoi(kStr);
                
                while(k--){
                    for(char ch: s)
                        st.push(ch);
                }
                
            }
        }
        
        string res;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
    
    //T - O(length of Decoded string)
    //S - O(length of Decoded string)
};