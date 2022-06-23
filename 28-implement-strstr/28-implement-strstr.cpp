class Solution {
    
    int mod = 1e9+7;
    int base = 256;
    
public:
    
    bool isEqual(string &txt, int &si, string &pat){
        for(int i = 0; i<pat.size(); i++){
            if(txt[i+si] != pat[i]) return false;
        }

        return true;
    }
    
    int strStr(string txt, string pat) {
        if(pat.size() == 0) return 0;
        else if(pat.length() > txt.length()) return -1;
        
        long patHash = 0, winHash = 0;
        long wt = 1;

        int len = pat.size();
        for(int i = pat.size()-1; i>=0; i--){

            patHash += pat[i]*wt; patHash %= mod;
            winHash += txt[i]*wt; winHash %= mod;

            if(i!=0)
            wt = (wt*base)%mod;
        }

        int ans = -1;

        for(int i = 0; i<=txt.size()-pat.size(); i++){ //i is start of current window
            if(patHash == winHash && isEqual(txt, i, pat)){
                ans = i;
                break;
            }

            winHash -= (txt[i]*wt)%mod;
            if(winHash < 0) winHash = winHash+mod;
            winHash *= base; winHash %= mod;
            winHash += txt[i+len]; winHash %= mod;
        }

        return ans;
    }
    //Tavg - O(n), Tworst - O(n*m)
    //S - O(1)
};