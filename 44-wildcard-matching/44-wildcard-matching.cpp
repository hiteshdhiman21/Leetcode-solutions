class Solution {
public:
    
    bool isMatch(string s, string p) {
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
        
        /*for(int i =0; i<=m; i++){
            for(int j =0; j<=n; j++){
                cout << match[i][j] << " ";
            }
            cout << endl;
        }*/
        
        return match[0][0];
    }
};