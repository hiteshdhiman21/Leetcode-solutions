class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        //Step-1. Maintaining a stack such that it always contains the element in increasing order.
        //Step-2. Travelling from end and while(st.top() < cur_value) remove those from stack.
        //Step-3. If stack is not empty then put ans[i] = st.top()/
        //Step-4. Put cur_value into stack.
        //Intuition - For values in left side, cur_value is more closer to them than the removed elements. And as cur_value is also greater than them, being more closer and greater than removed elements, it will serve as the next greater elements for left-side values smaller than it as well as smaller than the removed elements.(It will overshadow them:- Think in terms of hills)
        
        int n = nums.size();
        vector<int> ans(n);
        
        stack<int> st;
        
        for(int i=2*n-1; i>=0; i--){ //start at i=2n-1 for getting the values in circular fashion
                                     //for non-circular start from i = n-1
            while(!st.empty() && st.top()<= nums[i%n]){
                st.pop();
            }
            
            if(i<n){
                if(st.empty()) ans[i] = -1;
                else ans[i] = st.top();
            }
            
            st.push(nums[i%n]);            
        }
        
        return ans;
    }
    //T - 2n+2n
    //S - O(n)
};