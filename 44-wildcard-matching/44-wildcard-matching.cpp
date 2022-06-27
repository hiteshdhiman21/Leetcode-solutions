class Solution {
public:
    
    bool isMatch(string s, string p) {
      /*Use m and n fully and also update them fully. 
        Many corner cases: case1: "a", "a**". case2: "", "*". Case3: "abcdeabf", "a***c*bf**".*/   
        int n = s.size(), m = p.size();
        vector<vector<bool>> match(m+1, vector<bool>(n+1));
        
        match[m][n] = true;
        for(int i=m; i>=0; i--){

            for(int j=n; j>=0; j--){
                if((p[i] == '?' || p[i] == s[j]) && i+1 <=m && j+1 <= n && match[i+1][j+1])
                    match[i][j] = true;
                else if(p[i] == '*' && (i+1 <= m && match[i+1][j] || j+1 <= n && match[i][j+1]))
                    match[i][j] = true;
            }
        }       
        
        return match[0][0];
    }
    //T - O(n*m)
    //S - O(n*m) can be modified to O(n)
};