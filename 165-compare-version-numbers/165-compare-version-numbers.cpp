class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.size(), m = version2.size();
        int i = 0, j = 0;
        
        while(i<n && j<m){
            unsigned int rev1 = 0;
            while(i<n && version1[i] != '.'){
                rev1 = rev1*10+version1[i]-'0';
                i++;
            }
               
            unsigned int rev2 = 0;
            while(j<m && version2[j] != '.'){
                rev2 = rev2*10+version2[j]-'0';
                j++;
            }
                
            if(rev1 < rev2) return -1;
            else if(rev1 > rev2) return 1;
            
            i++; j++;
        }
        
        while(i<n){
            if(version1[i] >= '1' && version1[i] <= '9') return 1;
            i++;
        }
        
        
        while(j<m){
            if(version2[j] >= '1' && version2[j] <= '9') return -1;
            j++;
        }
        
        return 0;
    }
    //T - O(n+m)
    //S - O(1)
};