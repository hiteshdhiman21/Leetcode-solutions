class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for(int x:asteroids){
            if(x > 0)
                st.push(x);
            else{
                while(!st.empty() && st.top()>0 && st.top()<abs(x))
                    st.pop();
                
                if(st.empty() || st.top() < 0) st.push(x);
                else if(st.top()==abs(x)) st.pop();
            }
        }
        
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
        
    }
};