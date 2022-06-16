class Node{
    public:
    vector<Node*> links;
    bool isEnd;
    
    Node(){
        this->links.assign(26, NULL);
        isEnd = false;
    }
    
    bool containsKey(char& ch){
        return this->links[ch-'a'] != NULL;
    }
    
    void put(char &ch){
        this->links[ch-'a'] = new Node;
    }
    
    Node* get(char &ch){
        return this->links[ch-'a'];
    }
};

class WordDictionary {
Node *root;
    
public:
    
    WordDictionary() {
        root = new Node;
    }
    
    void addWord(string word) {
        Node *cur = root;
        for(char& ch: word){               
            if(!cur->containsKey(ch))
                cur->put(ch);
            cur = cur->get(ch);
        }
        cur->isEnd = true;
    }
    
    bool searchWord(string& word, int ind, Node *cur){
        if(ind == word.size())
            return cur->isEnd;
        
        if(word[ind] == '.'){
            for(char assume = 'a'; assume <= 'z'; assume++){
                if(cur->containsKey(assume) && searchWord(word, ind+1, cur->get(assume)))
                    return true;
            }
            return false;
        }else{
            if(!cur->containsKey(word[ind]))
                return false;
            return searchWord(word, ind+1, cur->get(word[ind]));
        }        
    }
    
    bool search(string word) {
        return searchWord(word, 0, root);
    }
    //T - O(n)
    //S - O(<n*k) can't be counted for Tries
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */