class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res(digits.size());
        int c = 1;
        for(int i=(int)digits.size()-1; i>=0; i--){
            int sum = c+digits[i];
            c = sum/10;
            sum = sum%10;
            
            res[i] = sum;
        }
        
        if(c == 1)
            res.insert(res.begin(), c);
            
        return res;
    }
    //T - O(n)
    //S - O(1)
};