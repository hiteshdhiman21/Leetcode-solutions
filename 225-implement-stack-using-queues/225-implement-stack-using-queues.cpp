//Advice: Think of the push operation in a recursive way. It will be easy to understand.
class MyStack {
    private:
    queue<int> q;
    
public:
    /** Initialize your data structure here. */
    MyStack() { }
    
    /** Push element x onto stack. */
    void push(int x) {
        //Assume q follows the stack property in a FIFO way.
        //Push new element to queue from behind.
        //Repush all the element from start to end except the newly pushed element into the queue.
        //Now q again follows the stack property in a FIFO way.
        
        q.push(x);
        for(int i=1; i<=(int)q.size()-1; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        //As q follows the stack property in FIFO Way. Remove front element from q.
        int x = q.front(); 
        q.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.size() == 0;
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