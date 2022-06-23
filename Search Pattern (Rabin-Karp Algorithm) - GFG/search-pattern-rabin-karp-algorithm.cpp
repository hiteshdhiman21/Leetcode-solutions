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
            //Rabin- karp 
            //Rolling hash type: str = "abyz", a*pow(256,3) + b*pow(256,2) + y*pow(256,1)+ z*pow(256, 0) with appropriate mod in between.
          /*Step-1. First develop winHash and patHash
            Step-2. Now start iterating over text and check if patHash == winHash. If true, then only check if the current substring and pattern are equal 
                    or not. If equal, then push the index into res vector.
            Step-3. Finally update winHash for the next txt substring in O(1) time.
            */
            long patHash = 0, winHash = 0;
            long wt = 1;
            
            int len = pat.size();
            for(int i = pat.size()-1; i>=0; i--){
               
                patHash += pat[i]*wt; patHash %= mod;
                winHash += txt[i]*wt; winHash %= mod;
                
                if(i!=0)
                wt = (wt*base)%mod;
            }
            
            
            vector<int> res;
   
            for(int i = 0; i<=txt.size()-pat.size(); i++){ //i is start of current window
                if(patHash == winHash && isEqual(txt, i, pat))
                    res.push_back(i+1);
                    
                winHash -= (txt[i]*wt)%mod;
                if(winHash < 0) winHash = winHash+mod;
                winHash *= base; winHash %= mod;
                winHash += txt[i+len]; winHash %= mod;
            }
            
            if(res.size() == 0) return {-1};
            
            return res;
            
        }
        //T - O(n*m)   //Avg case is far less O(n) < Tavg < O(n*m). Where n = txtLength and m = patLength
        //S - O(1)
     
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