//Advice: Think of the push operation in a recursive way. It will be easy to understand.


class MyStack {
    private:
    queue<int> q1;
    queue<int> q2;
    
    
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        //Assume q1 follows the stack property in a FIFO way.
        //Push new element to queue.
        //Push q1 elements into queue.
        //Now q2 also follows the stack property in a FIFO way.
        //Just swap q1 and q2. Now q1 follows the stack property(in FIFO way) and q2 is empty.
        
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        //As q1 follows the stack property in FIFO Way. Remove element from q1.
        int x = q1.front(); 
        q1.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.size() == 0;
    }
    
    //Push - O(n), Pop - O(1)
    //S - O(n)
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */