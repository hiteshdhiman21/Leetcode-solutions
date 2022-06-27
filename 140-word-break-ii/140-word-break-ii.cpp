class Node{
    public:
    vector<Node*> links;
    bool end;
    
    Node(){
        links.assign(26, NULL);
        end = false;
    }
    
    bool isEnd(){
        return this->end;
    }
    
    void setEnd(){
        this->end = true;
    }
    
    Node* get(char ch){
        return this->links[ch-'a'];
    }
    
    void put(char ch){
        this->links[ch-'a'] = new Node();
    }
    
    bool containsKey(char ch){
        return this->links[ch-'a'] != NULL;
    }
};

class Trie {
private:
    Node *root;

public:
    
    vector<string> res;
    Trie() {
        root = new Node;
        res.clear();
    }
    
    void insert(string& word) {
        Node *cur = root;
        for(int i=0; i<word.size(); i++){
            if(!cur->containsKey(word[i])) cur->put(word[i]);
            cur = cur->get(word[i]);
        }
        
        cur->setEnd();
    }
    
    void search(string& s, int ind, string ds) {
        if(ind == s.size()){
            res.push_back(ds);
            res.back().pop_back();
            return;
        }
            
        Node *cur = root;
        
        int i;
        for(int i=ind; i<s.size(); i++){
            if(!cur->containsKey(s[i])) break;
            ds += s[i];
            
            cur = cur->get(s[i]);
            if(cur->isEnd()){
                ds.push_back(' ');
                search(s, i+1, ds);
                ds.pop_back();
            }  
        }
        
        i--;
        while(i >= ind && ds.size() > 0){
            ds.pop_back();
            i--;
        }
    }
    
    void solve(string& s){
        string ds;
        search(s, 0, ds);
    }
    
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie *t = new Trie;
        for(string &str: wordDict)
            t->insert(str);
        
        t->solve(s);
        return t->res;
    }
};