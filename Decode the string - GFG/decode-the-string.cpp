// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string str){
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
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends