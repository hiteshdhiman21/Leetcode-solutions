class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //Step-1. For each ind travel through the whole strs array and check if this ind contains the same character in each string.
        //Step-2. If yes add this character to ans and do ind++ and check for other indices. Because this char is in prefix of all the strings.
        //Step-3. Else do not add and just break.
        
        int n = strs.size();
        string ans = "";
        int ind =0;
        while(true){
            bool ok = true;
            for(auto &str:strs){
                if(str.size() <= ind || str[ind] != strs[0][ind]) ok = false;
            }
            if(ok){
                ans += strs[0][ind];
                ind++;
            }else{
                break;
            }
        }
        return ans;
    }
    //T - O(no_of_strs*min_str_length)
    //S - O(min_str_length)
};