class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       
        for(int i=(int)digits.size()-1; i>=0; i--){
            if(digits[i] < 9){
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        
        digits.insert(digits.begin(), 1);
        return digits;
    }
    //T - O(n)
    //S - O(1)
};