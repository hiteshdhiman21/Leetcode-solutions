//Maintain an additional stack mst with a normal stack st
//We will maintain minimum element on top of mst so to perform getMin() in O(1). So we will store elements in mst in increasing order from the top.
//Push(x) -> st.push(x). if x <= mst.top(), also do mst.push(x)
//Pop() -> if st.top() == mst.top(), we also need to pop from the mst

class MinStack {
public:
    stack<int> st;
    stack<int> mst;
    
public:
    MinStack() {    }
    
    void push(int val) {
        st.push(val);
        if(mst.empty() || mst.top() >= val) mst.push(val);
    }
    
    void pop() {
        if(st.top() == mst.top()){
            st.pop(); mst.pop();
        }else{
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mst.top();
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