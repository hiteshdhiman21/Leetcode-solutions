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
    
    bool isHappy(int n) {
        unordered_set<int> s;
        
        while(n!=1){
            if(s.count(n) > 0) return false;
            s.insert(n);
            n = next(n);
        }
        
        return true;
    }
    //T - logn + log(logn) + log(log(logn)) + log(log(log(logn))) = log(n)
    //As 10^(n) will become <= 81*n, Hence n digit no. become <= n. Hence num become <= log10(num)
    //999999999 -> 1053, 9999 -> 324, 999 -> 243, 99 ->162, 9 -> 81. So, 9 digit num will become  3 digit in 2 steps and then it will stay <= 243.
    //S - O(logn)
};