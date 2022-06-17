class Solution {
public:
   /* void rotate(vector<int>& nums, int k) {
      Step-1. Reverse the whole array. Last k elements now will be in first k positions and first n-k will now be at the last n-k positions (both in reverse order).
        Step-2. Now just reverse the first k and last n-k elements separately and we will get the required array
      
        k = k%nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
    //T - O(2n)
    //S - O(1)*/
    
    void rotate(vector<int>& nums, int k) {
      /*Step-1. Take each element at its correct position. (all at a distance of k in one iteration)
        Step-2. Then do start++ and begin a new iteration from that start. 
        (Fact: Start+1 will always start a new cycle. Because if in the previous cycle start+1 has occured, then start+2, +3 and similarly all elements have been swapped in the previous cylce. And so in that case (start+1) will not start at any cycle due to cntRotated == n in that case. But if that is not the case, then start+1 will definitely start a new cycle.
        */
        
        int n = nums.size();
        k = k%n;
        int cntRotated = 0; 
        int start = 0, curr = 0;
        
        while(cntRotated < n){
            curr = start;
            int numToBeRotated = nums[curr];
            
            do{
                int tmp = nums[(curr+k)%n];
                nums[(curr+k)%n] = numToBeRotated;
                numToBeRotated = tmp;
                curr = (curr+k)%n;
                cntRotated++;
            }while(curr != start);
            
            start++;
        }
    }
    //T - O(n)
    //S - O(1)
    
};