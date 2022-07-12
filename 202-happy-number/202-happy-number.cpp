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
      /*Approach: Floyd Warshall Hare and Tortoise cycle detection algorithm*/  
        int fr = n, sr = n;
        
        do{
            fr = next(next(fr));
            sr = next(sr);
        }while(fr != sr && sr != 1);
        
        return (sr==1);
    }
    //T - nRounds*(logn + log(logn) + log(log(logn)) + log(log(log(logn)))) = nRounds*log(n) = log(n)
    //Suppose there k steps in cycle. And SR-FR == k. It will take max k steps for both of them to coincide as FR get 1 step closer to SR in each step. Hence nRounds <= 2(actually just a little round more than 1). Hence max no of steps <= k steps.
    //As 10^(n) will become <= 81*n, Hence n digit no. become <= n. Hence num become <= log10(num)
    //999999999 -> 1053, 9999 -> 324, 999 -> 243, 99 ->162, 9 -> 81. So, 9 digit num will become  3 digit in 2 steps and then it will stay <= 243.
    //S - O(1)
};