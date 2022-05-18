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
    Trie() {
        root = new Node;
    }
    
    void insert(string word) {
        Node *cur = root;
        for(int i=0; i<word.size(); i++){
            if(!cur->containsKey(word[i])) cur->put(word[i]);
            cur = cur->get(word[i]);
        }
        
        cur->setEnd();
    }
    
    bool search(string word) {
        Node *cur = root;
        for(int i=0; i<word.size(); i++){
            if(!cur->containsKey(word[i])) return false;
            cur = cur->get(word[i]);
        }
        
        return cur->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *cur = root;
        for(int i=0; i<prefix.size(); i++){
            if(!cur->containsKey(prefix[i])) return false;
            cur = cur->get(prefix[i]);
        }
        
        return true;
        }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */