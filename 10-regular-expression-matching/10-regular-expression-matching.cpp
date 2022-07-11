class Solution {
public:
    
    bool solve(string &s, string &p, int i1, int i2, char &prvCh){
        //cout << i1 << " " << i2 << " " << prvCh << endl;
        
        if(i1 == s.size() && i2 == p.size())
            return true;
        else if(i2 == p.size())
            return false;
        else if(i1 == s.size() + 1)
            return false;
        
        int n1 = s.size(), n2 = p.size();
        
        if(i2+1<n2 && p[i2+1] == '*' ){
            return solve(s, p, i1, i2+1, p[i2]);
        }else if(p[i2] == '*'){
            bool res = solve(s, p, i1, i2+1, p[i2]);
            if(i1 < s.size() && prvCh == s[i1] || prvCh == '.')
            res = res | solve(s, p, i1+1, i2, prvCh);
            return res;
        }else if(i1 < s.size() && s[i1] == p[i2] || p[i2] == '.'){
            return solve(s, p, i1+1, i2+1, p[i2]);
        }
        return false;
    }
    
    bool isMatch(string s, string p) {
        char prvCh = '1';
        return solve(s, p, 0, 0, prvCh);
    }
    //T - O(n*m)
    //S - O(n*m) can be modified to O(n)
};