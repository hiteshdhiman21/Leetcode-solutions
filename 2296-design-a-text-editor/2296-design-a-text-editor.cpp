class TextEditor {
public:
    
    deque<char> before, after;
    
    TextEditor() {
        before.clear();
        after.clear();
    }
    
    void print(deque<char> dq, deque<char> dq2){
        /*while(!dq.empty()){
            cout<< dq.front();
            dq.pop_front();
        }
        cout << "  "; 
        while(!dq2.empty()){
            cout<< dq2.front();
            dq2.pop_front();
        }
        cout << endl;*/
    }
    
    void addText(string text) {
         for(char& ch: text) before.push_back(ch);
       // print(before, after);
    }
    
    int deleteText(int k) {
        int cnt = 0;
        while(!before.empty() && cnt < k){
            before.pop_back();
            cnt++;
        }
        //print(before, after);
        return cnt;
    }
    
    string cursorLeft(int k) {
        int cnt = 0;
        while(!before.empty() && cnt < k){
            after.push_front(before.back());
            before.pop_back();
            cnt++;
        }
        
        cnt = 0;
        string res = "";
        while(!before.empty() && cnt < 10){
            res.push_back(before.back());
            before.pop_back();
            cnt++;
        }
        
        reverse(res.begin(), res.end());
        for(char &ch: res)
            before.push_back(ch);
        //print(before, after);
        return res;
    }
    
    string cursorRight(int k) {
        int cnt = 0;
        while(!after.empty() && cnt < k){
            before.push_back(after.front());
            after.pop_front();
            cnt++;
        }
        
        cnt = 0;
        string res = "";
        while(!before.empty() && cnt < 10){
            res.push_back(before.back());
            before.pop_back();
            cnt++;
        }
        
        reverse(res.begin(), res.end());
        for(char &ch: res)
            before.push_back(ch);
        //print(before, after);
        return res;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */