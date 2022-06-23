class Solution {
public:
    int base = 256;
    int mod = 1e9+7;
    
    bool isEqual(string &a, int& si, string &b){
        for(int i = 0; i<b.size(); i++){
            if(a[(i+si)%a.size()] != b[i])
                return false;
        }
        
        return true;
    }
    
    int repeatedStringMatch(string a, string b) {
        //Rabin karp
        long bHash = 0, aHash = 0;
        long wt = 1;
        int blen = b.size();
        
        for(int i = b.size()-1; i>=0; i--){
            bHash += wt*b[i]; bHash%=mod;
            aHash += wt*a[i%a.size()]; aHash%=mod;
            
            if(i!=0)
            wt *= base, wt%=mod;
        }
        
        int indA = -1;
        for(int i = 0; i<a.size(); i++){
            if(bHash == aHash && isEqual(a, i, b)){
                indA = i; break;
            }
            aHash -= (a[i]*wt)%mod;
            if(aHash < 0) aHash += mod;
            aHash *= base; aHash %= mod;
            aHash += a[(i+blen)%a.size()]; aHash %= mod;
        }
        
        if(indA == -1)  return indA;
        else return (indA+blen-1)/a.size() + 1; //Finding repetition accoring to lastIndex needed
    }
    //T - O(alen*blen) in the worst case and O(alen+blen) in the avg case
    //S - O(1)
};