class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        cnt++;
        for(int i=0; i<n; i++){
            
            int j = i-1, k=i-1;
            while(j>=0 && k<=n-1 && s[j] == s[k]){
                cnt++;
                j--; k++;
            }
            
            j = i, k=i+1;
            while(j>=0 && k<=n-1 && s[j] == s[k]){
                cnt++;
                j--; k++;
            }
            
        }
        return cnt;
    }
};