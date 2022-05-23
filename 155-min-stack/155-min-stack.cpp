//Push(x) -> If x < mn, push(2*x - mn) and do mn = x
//Pop() -> if st.top() < mn, return st.top() and do mn = 2*mn-st.top(). else return st.top()

class MinStack {
public:
    stack<long long> st;
    long long mn;
    
public:
    MinStack() { mn = INT_MAX;   }
    
    void push(int val) {
        if(val>= mn){
            st.push(val);
            mn = min(mn, (long long)val); //Also true in empty case
        }else{
            st.push(2ll*val-mn);
            mn = val;
        }
    }
    
    void pop() {
        if(st.top() < mn){
           mn = 2*mn-st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top() < mn) return mn;
        else return st.top();
    }
    
    int getMin() {
        return mn;
    }
    //T - O(1) for all operations
    //S - O(n) maintaining an additional min stack in addition to normal stack
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */