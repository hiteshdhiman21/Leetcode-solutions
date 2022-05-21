class MyQueue {

stack<int> in; //Will store in LIFO order
stack<int> out; //Will store in FIFO order
    
public:
    MyQueue() {
    }
    
    void push(int x) {
        in.push(x);
    }
    
    //Here out will store in the correct FIFO order. So if out is not empty we will just return from its top.
    //Else we will transfer all the elements from in to out.(Elements inserted in in:1 2 3 4 5), Elements coming out from in: 5 4 3 2 1. Elements going to out: 5 4 3 2 1. So element coming out from out: 1 2 3 4 5(same as the input order)
    //fill in : 1 2 3
    //empty in: LIFO - 3 2 1
    //fill out: order - 3 2 1 
    //empty out: LIFO - 1 2 3
    int pop() {
        if(out.empty()){
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
        
        int x = out.top();
        out.pop();
        return x;
    }
    
    int peek() {
        if(out.empty()){
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }

        return out.top();
    }
    
    bool empty() {
        return in.size() == 0 && out.size() == 0;
    }
    
    //T - Push(1), Pop(am_1), Top(am_1)
    //S - O(n)
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */