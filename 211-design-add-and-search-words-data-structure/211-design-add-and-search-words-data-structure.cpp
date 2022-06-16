class Node{
    public:
    vector<Node*> links;
    bool isEnd;
    
    Node(){
        this->links.assign(26, NULL);
        isEnd = false;
    }
    
    bool containsKey(const char& ch){
        return this->links[ch-'a'] != NULL;
    }
    
    void put(const char &ch){
        this->links[ch-'a'] = new Node;
    }
    
    Node* get(const char &ch){
        return this->links[ch-'a'];
    }
};


//using Trie
class WordDictionary {
Node *root;
    
public:
    
    WordDictionary() {
        root = new Node;
    }
    
    //As usual iterative
    void addWord(const string&  word) {
        Node *cur = root;
        for(const char& ch: word){               
            if(!cur->containsKey(ch))
                cur->put(ch);
            cur = cur->get(ch);
        }
        cur->isEnd = true;
    }
    
    //Simple recursive solution 
    bool searchWord(const string&  word, int ind, Node *cur){
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
    
    bool search(const string& word) {
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