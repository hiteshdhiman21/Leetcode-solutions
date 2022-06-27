class Solution {
public:
    
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> match(m+1, vector<bool>(n+1));
        
        match[m][n] = true;
        bool isGoing = true;
        for(int i=m-1; i>=0; i--){
            if(p[i] != '*')
                isGoing = false;
            
            if(isGoing)
                match[i][n] = true;
            for(int j=n-1; j>=0; j--){
                if( (p[i] == '?' || p[i] == s[j]) && match[i+1][j+1])
                    match[i][j] = true;
                else if(p[i] == '*' && (i==m-1 || match[i+1][j] || match[i][j+1]))
                    match[i][j] = true;
            }
        }
        
        /*for(int i = 0; i<=m; i++){
            for(int j=0; j<=n; j++){
                cout << match[i][j] << " " ;
            }
            cout << endl;
        }*/
        
        return match[0][0];
    }
};