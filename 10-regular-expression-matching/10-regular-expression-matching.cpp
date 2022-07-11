class Solution {
public:      
      
       /*Valid inputs for pattern: ab, abb, a*.., ab*, a.*, ab*c*.
        Invalid inputs for pattern: a**, *ab, ab*c**c
        
        Step-1. If s and p both ends. means both are matched. Hence return true
        Step-2. If p reaches end but s still remains return false. As there is no p to match s further.
        Step-3. If s reached end and p can also reach end without any mathcing [cases Prem = "*", "a*", ".*"] return true. Else if p can't reach end without matching any character, Return false.
        Step-4. p[i2+1] == '*', It means we can skip p[i2] and directly go to (i1, i2+2) or we can use p[i2] if p[i2] == '.' || s[i1] == p[i2] and again go to (i1+1, i2) for the same choice again.
        Step-6. If s[i1] == p[i2] || p[i2] == '.', it means i1 and i2 can match hence go to (i1+1, i2+1). Else it means both can't be matched. return False.*/
    
    bool isMatch(string s, string p) {
        int n1 = s.size(), n2 = p.size();
        vector<vector<bool>> dp(3, vector<bool>(n2+1, false));
        dp[n1%3][n2] = true;
        
        for(int i1=n1; i1>=0; i1--){
            for(int i2=n2; i2>=0; i2--){
                
                dp[i1%3][i2] = false;
                if(i2 < n2 && p[i2] == '*') continue;
                if(i1 == n1 && i2 == n2) dp[n1%3][n2] = true;
                
                if(i2+1 < n2 && p[i2+1] == '*'){
                    dp[i1%3][i2] = dp[i1%3][i2+2];
                    if(i1 < n1 && (s[i1] == p[i2] || p[i2] == '.'))
                       dp[i1%3][i2] = dp[i1%3][i2] | dp[(i1+1)%3][i2];
                }else if(i1 < n1 && (s[i1] == p[i2] || p[i2] == '.'))
                       dp[i1%3][i2] = dp[(i1+1)%3][i2+1];
            }
        }
        
        return dp[0][0];
    }
    //T - O(3n)
    //S - O(n*m) can be modified to O(n)
};