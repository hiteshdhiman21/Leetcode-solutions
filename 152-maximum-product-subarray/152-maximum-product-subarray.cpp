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
        int minSub = 1, maxSub = 1;
        int maxProd = INT_MIN;
        
        for(int i =0; i<nums.size(); i++){
            minSub = minSub>1?nums[i]:minSub*nums[i];
            maxSub = maxSub<1?nums[i]:maxSub*nums[i];
            
            if(minSub > maxSub) swap(minSub, maxSub);
            
            
            maxProd = max(maxProd, maxSub);
            
            minSub = minSub==0?1:minSub;
            maxSub = maxSub==0?1:maxSub;
            
        }
        
        return maxProd;
    }
    
};