class Solution {
    
public:
    
    void makeLPS(vector<int> &lps, int& m, string& pat){
        int i =1, prevLPS = 0;
        while(i<m){
            if(pat[i] == pat[prevLPS]){
                lps[i] = prevLPS+1;
                prevLPS++;
                i++;
            }else if(prevLPS == 0){
                lps[i] = 0;
                i++;
            }else{
                prevLPS = lps[prevLPS-1]; 
            }
        }
        
    }
    
    int strStr(string txt, string pat) {
        //Make Lps
        int n = txt.size(), m = pat.size();
        vector<int> lps(m, 0);
        makeLPS(lps, m, pat);
        
        
        
        int i = 0, j = 0;
        while(i < n){
            if(txt[i] == pat[j]){
                i++; j++;
            }else if(j!=0){
                j = lps[j-1];
            }else{
                i++;
            } 
            
            if(j == m) return i-m;
        }   
        
        return -1;       
    }
    //T - O(n+m)
    //S - O(m)
};