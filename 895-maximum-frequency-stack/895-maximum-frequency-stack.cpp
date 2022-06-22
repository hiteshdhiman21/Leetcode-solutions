class FreqStack {
    
    map<int, stack<int>> freqBuck;
    unordered_map<int, int> freq;
    int maxFreq = 0;
    
public:
    FreqStack() {
    }
    
    void push(int val) {
        freqBuck[++freq[val]].push(val);
        maxFreq = max(maxFreq, freq[val]);
    }
    
    int pop() {
        int val = freqBuck[maxFreq].top();
        freqBuck[maxFreq].pop();
        freq[val]--;
        
        if(freqBuck[maxFreq].empty())
            maxFreq--;
        
        return val;
    }
    //T - O(1) for each operation
    //S - O(n)
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */