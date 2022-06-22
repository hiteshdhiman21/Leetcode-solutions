class FreqStack {
    
    vector<vector<int>> freqBuck;
    unordered_map<int, int> freq;
    int maxFreq = 0;
    
public:
    FreqStack() {
        freqBuck.resize(1e5);
    }
    
    void push(int val) {
        freq[val]++;
        freqBuck[freq[val]].push_back(val);
        maxFreq = max(maxFreq, freq[val]);
    }
    
    int pop() {
        int val = freqBuck[maxFreq].back();
        freqBuck[maxFreq].pop_back();
        if(freqBuck[maxFreq].size() == 0)
            maxFreq--;
        freq[val]--;
    
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