class StockSpanner {
    
public:
    stack<pair<int,int>> st;
    int day;
    
public:
    StockSpanner() { day=0;}
    
    //Similar to previous greater element. Maintain a increasing stack(Top-Bottom)
    int next(int price) {
        day++;
        
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        
        int ans = 0;
        if(st.empty()) ans = day;
        else ans = day-st.top().second;
        
        st.push(make_pair(price, day));
        return ans;
    }
    
    //T - O(n)  
    //S - O(n)
    
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */