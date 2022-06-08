class Solution {
public:
    /*int maxProduct(vector<int>& nums) {
        int lProd = 1;
        int rProd = 1;
        int ans = INT_MIN;
        
        int n= nums.size();
        
        for(int i=0, j=n-1 ; i<nums.size(), j>=0; i++, j--){
                        
            lProd = (lProd==0)?1:lProd;
            rProd = (rProd==0)?1:rProd;
            
            lProd *= nums[i];
            rProd *= nums[j];
            
            ans = max(ans, max(lProd, rProd));
        }
        
        return ans;
        //Because max can only be any prefix or suffix(If we not have any zero elements).
        //In case of zeroes, for the next part we are updating product, means we are treating the next part
        //as new part and the max can now also be its prefix or suffix.
    }
    
    int maxProduct(vector<int>& nums) {
        
        int minSub =1;
        int maxSub =1;
        int ans = INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
            
            minSub = (minSub==0)?1:minSub;
            maxSub = (maxSub<=0)?1:maxSub;
                    
            minSub *= nums[i];
            maxSub *= nums[i];
            
            if(minSub > maxSub){
                swap(minSub, maxSub);
            }
            
            ans = max(ans, maxSub);
            
        }
        
        return ans;
    }*/
    
    /*int maxProduct(vector<int>& nums) {
        //Fact: For a subarray containing only integer values except 0, the max product can be its suffix or prefix (Ofcourse full array can be termed as suffix and prefix) only.(Take 2 to 3 cases)
        //Step-1. Iterate over the array from starting and ending and maintain two products prefProd and suffProd respectively.
        //Step-2. While nums[i] != 0, keep multiplying prefProd with the nums[i] and similary do with the suffProd.
        //Step-3. keep updating ans = max(ans, prefProd, suffProd)
        
        int prefProd = 1, suffProd = 1;
        int maxProd = INT_MIN;
        
        for(int i =0; i<nums.size(); i++){
            prefProd = nums[i]==0?1:prefProd*nums[i];
            suffProd = nums[nums.size()-1-i]==0?1:suffProd*nums[nums.size()-1-i];
            
            if(nums[i] == 0 || nums[nums.size()-1-i] == 0) maxProd = max(maxProd, 0);
            if(nums[i] != 0) maxProd = max(maxProd, prefProd);
            if(nums[nums.size()-1-i] != 0) maxProd = max(maxProd, suffProd);
        }
        
        return maxProd;
    }
    //T - O(n)
    //S - O(1)
    */
    
    int maxProduct(vector<int>& nums) {
        //Intuition: Min possible product can become max possible product (if multiplied with negative element) and max possible product will stay max (if multiplied with positive element)
        //Just see the code
        //maxSub denote the possible maxSub and minSub if it is neccesary to pick up nums[i].
        //case 1: nums[i] < 0: Then maxSub will become the minimum possible subarray product till that element if it is necessary to take nums[i] and minSub will become maximum possible subarray product.
        //case 2: nums[i] > 0: Then maxSub will become the maximum possible subarray product till that element if it is necessary to take nums[i] and minSub will become minimum possible subarray product.
        int minSub = 1, maxSub = 1;
        int maxProd = INT_MIN;
        
        for(int i =0; i<nums.size(); i++){
            minSub = minSub>=0?nums[i]:minSub*nums[i]; //If minSub >= 0, then maxSub will be greater than that and so minSub only acquire negative nums[i] while maxSub acquire some bigger negative value. so, that bigger negative value will be transferred in step3 to minSub. And maxSub will get some lesser negative value after that step3.
            maxSub = maxSub<=0?nums[i]:maxSub*nums[i];//If maxSub <= 0, then it will be better to take nums[i] only as it is greater negative value at this point. minSub will be lesser negative or positive after this point. So the swapping will occur in step-3. And maxSub will become greater  and minSub will become lesser after that.
            
            if(minSub > maxSub) swap(minSub, maxSub);
            
            maxProd = max(maxProd, maxSub);
        }
        
        return maxProd;
    }
    
};