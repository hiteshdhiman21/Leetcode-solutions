class StockSpanner {
    
public:
    stack<pair<int,int>> st;
    int day;
    
public:
    StockSpanner() { day=0;  }
    
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
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */