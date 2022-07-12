class Solution {
public:
    
    int next(int n){
        int num = 0;
        while(n>0){
            num += (n%10)*(n%10);
            n /= 10;
        }
        
        return num;
    }
    
    unordered_set<int> s ={4, 16, 37, 58, 89, 145, 42, 20, 4};
    bool isHappy(int n) {
      /*Approach: Just hardcode. Not expected in interview
        There is only one Cycle: 4 -> 16 -> 37 -> 58 -> 89 -> 145 -> 42 ->20 -> 4.
        If a number is one of them. Then it will result in this cycle. And hence will not be a happy number. or If a number reaches any one of this no. it will get in a cycle and is not a happy number.
        See Leetcode Approach 3 and 4.
        */  
        
        while(n!=1 && n!=4) n = next(n);
        
        return n==1;        
    }
    //T - logn + log(logn) + log(log(logn)) + log(log(log(logn))) = log(n)
    //As 10^(n) will become <= 81*n, Hence n digit no. become <= n. Hence num become <= log10(num)
    //999999999 -> 1053, 9999 -> 324, 999 -> 243, 99 ->162, 9 -> 81. So, 9 digit num will become  3 digit in 2 steps and then it will stay <= 243.
    //S - O(1) hardcoded. Not maintaining previous seen numbers.
};