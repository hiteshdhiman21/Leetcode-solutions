class Solution {
public:
    
    bool solve(string &s, string &p, int i1, int i2,  vector<vector<int>> &dp){
      /*Valid inputs for pattern: ab, abb, a*.., ab*, a.*, ab*c*.
        Invalid inputs for pattern: a**, *ab, ab*c**c
        
        Step-1. If s and p both ends. means both are matched. Hence return true
        Step-2. If p reaches end but s still remains return false. As there is no p to match s further.
        Step-3. If s reached end and p can also reach end without any mathcing [cases Prem = "*", "a*", ".*"] return true. Else if p can't reach end without matching any character, Return false.
        Step-4. p[i2+1] == '*', just straight go to that index and from there try match i2 as many times as needed with i1.
        Step-5. If p[i2] == '*', Now either just skip it (i1, i2+1) or match it with i1 (i1+1, i2) (as i2 can also match with further i1).
        Step-6. If s[i1] == p[i2] || p[i2] == '.', it means i1 and i2 can match hence go to (i1+1, i2+1). Else it means both can't be matched. return False.*/
        
        int n1 = s.size(), n2 = p.size();
        
        if(i1 == n1 && i2 == n2) return true;
        else if(i2 == n2) return false;
        //If i1 surpasses the end of s1. Else if i1 is at end. We can wait for i2 to reach p end also. (cases like Prem = *, a*, b*a*c*)
        else if(i1 == n1+1) return false;
        
        if(dp[i1][i2] != -1)
            return dp[i1][i2];
        
        if(i2+1<n2 && p[i2+1] == '*' ){
            bool res = solve(s, p, i1, i2+2, dp);
            if(i1 < n1 && s[i1] == p[i2] || p[i2] == '.')
            res = res | solve(s, p, i1+1, i2, dp);
            return dp[i1][i2] = res;
        }else if(i1 < n1 && s[i1] == p[i2] || p[i2] == '.'){
            return dp[i1][i2] = solve(s, p, i1+1, i2+1, dp);
        }
        
        return dp[i1][i2] = false;
    }
    
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
        return solve(s, p, 0, 0, dp);
    }
    //T - O(n*m)
    //S - O(n*m) can be modified to O(n)
};