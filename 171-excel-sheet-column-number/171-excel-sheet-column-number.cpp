class Solution {
public:
    int titleToNumber(string textnum) {
      /*Numbers have weights like this : 26^n-1, 26^n-2, .......... , 26^2, 26^1, 26^0
        And digits are letters with the values given in Question.
        Read constraints: textNum range = ["A", "FXSHRXW"]*/
        int res = 0;
        for(int i = 0; i<textnum.size(); i++)
            res =  res*26 + (textnum[i]-'A'+1);
        

        return res;
    }
    //T - O(n)
    //S - O(1)
};