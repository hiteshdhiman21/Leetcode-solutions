class Solution {
public:
    int climbStairs(int n) {
        //Total ways from stepTaken+currentStepNo
        
        int step2 = 0, step1 =1;
        for(int AtStep=n-1; AtStep >= 0; AtStep--){
            int stepCur = step1 + step2;
            step2 = step1;
            step1 = stepCur;
        }
        
        return step1;
    }
    //T - O(n)
    //S - O(1)
};