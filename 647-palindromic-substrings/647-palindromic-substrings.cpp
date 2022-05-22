class Solution {
public:
    int countSubstrings(string s) {
        
        //Intuition: Fix each element as a center and try to expand the string maintaining it a center.
        //Fix each and its next element as a center and try to expand the string maintaining them a center.
        //If s[i] == s[j], do cnt++, i--, j++.
        
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
        //T - n^2
        //S - O(1)
    }
};