class CountIntervals {
    set<pair<int, int>> st;
    int cnt;
public:
    CountIntervals() {
        cnt = 0;
    }
    
    void add(int left, int right) {
        auto it = st.upper_bound(make_pair(left, 0));
        
        if(it!= st.begin() && (--it)->second < left){
            it++;
        }
        
        while(it != st.end() && it->first <= right){
            left = min(left, it->first);
            right = max(right, it->second);
            
            cnt -= (it->second-it->first+1);
            it = st.erase(it);           
        }
        
        st.insert(make_pair(left, right));
        cnt += right-left+1;
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */