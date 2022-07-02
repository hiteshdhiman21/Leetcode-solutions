class Node{
 
    public:
    vector<Node *> links;
    bool isEnd;
  
    Node(){
        links.assign(26, NULL);
        isEnd = false;
    }
    
    void setEnd(){
        isEnd = true;
    }
    
    bool getEnd(){
        return isEnd;
    }
    
    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }
    
    Node *get(char ch){
        return links[ch-'a'];
    }
    
    void put(char ch){
        links[ch-'a'] = new Node;
    }
    
    
};

class Trie{
    public:
    Node *root;
    
    Trie(){
        root = new Node;
    }
    
    void insert(string &word){
        Node *cur = root;
        for(char& ch: word){
            if(!cur->containsKey(ch))
                cur->put(ch);
            
            cur = cur->get(ch);
        }
        
        cur->setEnd();
    }
};



class Solution {
public:
    
     void dfs(vector<vector<char>>& board, int i, int j, Node *root, vector<string> &res, string &word) {
         if(i<0 || j<0 || i== board.size() || j == board[0].size() || board[i][j] == ' ' || !root->containsKey(board[i][j]))
             return;
         
         root = root->get(board[i][j]);
         word.push_back(board[i][j]);
         if(root->isEnd){
             res.push_back(word);
             root->isEnd = false;
         }
         
         char tempCh = board[i][j];
         board[i][j] = ' ';
         
         dfs(board, i+1, j, root, res, word);
         dfs(board, i, j+1, root, res, word);
         dfs(board, i-1, j, root, res, word);
         dfs(board, i, j-1, root, res, word);
         
         board[i][j] = tempCh;
         word.pop_back();
         
     }
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *t = new Trie;
        
        for(string &str: words)
            t->insert(str);
        
        Node *root = t->root;
        vector<string> res;
        
        
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[i].size(); j++){
                string word = "";
                dfs(board, i, j, root, res, word);
            }
        }
        
        return res;
    }
};