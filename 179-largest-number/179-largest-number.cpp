class Solution {
public:
    
    static bool comp(int& num1, int& num2){
        string num1s = to_string(num1);
        string num2s = to_string(num2);
        
        return num1s+num2s > num2s+num1s;
    }
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        string ans = "";
        for(int& x: nums){
            ans += to_string(x);
        }
        
        if(ans[0] == '0' && ans.back() == '0')
            return "0";
        
        return ans;
    }
    //T - O(nlogn)
    //S - O(n)
};