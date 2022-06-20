class Solution {
public:
    
    bool comp(int& num1, int& num2){
        string num1s = to_string(num1);
        string num2s = to_string(num2);
        
        return num1s+num2s > num2s+num1s;
    }
    
    void merge(vector<int> &nums, int& s, int& mid, int& e){
        vector<int> nums2;
        int i = s, j = mid+1;
       
        while(i<=mid && j<=e){
            if(comp(nums[i], nums[j]))
                nums2.push_back(nums[i++]);
            else
               nums2.push_back(nums[j++]); 
        }
        
        while(i<=mid){
            nums2.push_back(nums[i++]);
        }
        
        while(j<=e){
            nums2.push_back(nums[j++]); 
        }
        
        for(int i = 0; i<nums2.size(); i++){
            nums[s+i] = nums2[i];
        }
    }
    
    void mergeSort(vector<int> &nums, int s, int e){
        cout << s << " " << e << endl;
        if(s>=e)
            return;
        cout << s << " " << e << endl;
        int mid = s+(e-s)/2;
        
        mergeSort(nums, s, mid);
        mergeSort(nums, mid+1, e);
        
        merge(nums, s, mid, e);
    }
    
    string largestNumber(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        string ans = "";
        for(int& x: nums){
            ans += to_string(x);
        }
        
        if(ans[0] == '0' && ans.back() == '0')
            return "0";
        
        return ans;
    }
};