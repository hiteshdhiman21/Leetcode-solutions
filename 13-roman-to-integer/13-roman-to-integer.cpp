class Solution {
public:
    unordered_map <char, int> m = { {'I', 1},
                                    {'V', 5},
                                    {'X', 10},
                                    {'L', 50},
                                    {'C', 100},
                                    {'D', 500},
                                    {'M', 1000}};
        
                                
    int romanToInt(string s) {
        //Algorithm: As usually written in Large to Small order. So if order reverses for any 2 indices, do the special treatment. Else do the normal treatment.
        //Used map to make code much more readable.
        
        int ans = 0;
        for(int i = 0; i<s.size(); i++){
            if(i+1 < s.size() && m[s[i]] < m[s[i+1]]){
                ans += m[s[i+1]]-m[s[i]];
                i++;
            }else{
                ans += m[s[i]];
            }
        }
        
        return ans;
    }
    //T - O(n)
    //S - O(1) as Map size is fixed
};