class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        
        int n1 = nums1.size(), n2 = nums2.size();
        
        int totNeededInLeftHalf = (n1+n2+1)/2; // 9 -> 5   , 8 -> 4
        int low = 0, high = nums1.size();
        
        //Just using binary search on cut1, hence also deciding cut2 value.
        //If cut1 & cut2 are valid return median
        //Else if l1 > r2, means we need more element from cut2. Hence decrease high = cut1-1
        //Else if l2 > r1, means we need more element from cut1. Hence increase low = cut1+1
        
        while(low <= high){
            int cut1 = (low+high)/2;
            int cut2 = totNeededInLeftHalf - cut1;
            
            int l1 = (cut1 == 0)?INT_MIN:nums1[cut1-1];
            int l2 = (cut2 == 0)?INT_MIN:nums2[cut2-1];
            int r1 = (cut1 == n1)?INT_MAX:nums1[cut1];
            int r2 = (cut2 == n2)?INT_MAX:nums2[cut2];
            
            if(l1 <= r2 && l2 <= r1){
                if((n1+n2)%2 == 0){
                    return (max(l1, l2)+min(r1, r2))/2.0;
                }else{
                    return max(l1, l2);
                }
            }else if(l1 > r2){
                high = cut1-1;
            }else{
                low = cut1+1;
            }
        }
        return 0.0;
        
        //T- log(min(n1, n2)) , where n1 = array1 size and n2 array2 size
        //S - O(1)
    }
};