class Solution {
public:
        
    string decodeString(string str){
        
      /*Problem involve subproblems so intuition say use RECURSION or STACK
        Step-1. Iterate over all the characters ch of the string
        Step-2. If ch != ']', just push it into the stack
        Step-3. Else close bracket found and Hence we can decode this substring. Pop all the characters of the substring inside the corresponding [] brackets and also pop out the k before the bracker. Since the string will be popped in FILO order and we are adding in same order, There reverse the string. Since (int)k is also in reverse string format, so reverse it and then convert it into integer format.
        Step-4. Now after conversions, push the whole string k times into the stack (means decoded string).
        Step-5. Finally the whole string will be present in the stack so copy it in a string format and reverse it.
        Step-6. Finally return the string*/
        
        stack<char> st;
        for(char ch: str){
            if(ch != ']'){
                st.push(ch);
            }else{
                
                string s;
                while(st.top() != '['){ //Popping the string
                    s += st.top(); st.pop();
                }
                
                st.pop(); //Popping '['
                
                string kStr; //Popping k
                while(!st.empty() && isdigit(st.top())){
                    kStr += st.top(); st.pop();
                }
                
                reverse(s.begin(), s.end());
                reverse(kStr.begin(), kStr.end());
                
                int k = stoi(kStr);
                
                //Finally inserting the substring after decoding. (Inserting same string k times)
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