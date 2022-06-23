// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    int mod = 1e9+7;
    int base = 256;
    public:
        bool isEqual(string &txt, int &si, string &pat){
            for(int i = 0; i<pat.size(); i++){
                if(txt[i+si] != pat[i]) return false;
            }
            
            return true;
        }
    
        vector <int> search(string pat, string txt)
        {
            long patHash = 0, winHash = 0;
            long wt = 1;
            
            int len = pat.size();
            for(int i = pat.size()-1; i>=0; i--){
                int charVal = int(pat[i]);
                patHash = (patHash+(charVal*wt)%mod)%mod;
                
                charVal = int(txt[i]);
                winHash = (winHash+(charVal*wt)%mod)%mod;
                
                if(i!=0)
                wt = (wt*base)%mod;
            }
            
            vector<int> res;
            
            
            for(int i = 0; i<=txt.size()-pat.size(); i++){ //i is start of current window
                if(patHash == winHash && isEqual(txt, i, pat))
                    res.push_back(i+1);
                    
                int oldCharVal = int(txt[i]);
                int newCharVal = int(txt[i+len]);
              
                winHash = ((winHash - oldCharVal*wt)%mod + mod)%mod;
                winHash = (winHash*base)%mod;
                winHash = (winHash + newCharVal)%mod;
            }
            
            if(res.size() == 0) return {-1};
            
            return res;
            
        }
        /
     
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends