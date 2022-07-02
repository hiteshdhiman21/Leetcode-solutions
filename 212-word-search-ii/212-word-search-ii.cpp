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
      /*BackTracking Approach: Used DFS. Also used Trie for search optimization purpose   
        Step-1. Insert all the given words in a Trie.
        Step-2. Iterate through all the [i,j] indices in board and start dfs from there. 
        Step-3. For any index, if index is invalid or the board[i][j] is already taken or Trie doesn't contain board[i][j] after this much dfs. Just Return. Else, update trie->cur = board[i][j](i.e, take board[i][j]) and if cur->isEnd == true, it means the current word formed in dfs is present in the words, Therefore just push the word in res vector and set isEnd = false here so that same word will not be pushed again. Set board[i][j] = ' ', so that it wouldn't be taken again and do dfs on current index neighbours. Finally again reset board[i][j] so that it can be taken for other words.
        Step-4. Finally return res vector after finishing all the dfs.*/
        
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
    //T - O(totWords*avgWordLength + n*m*4^(n*m))
    //S - O(totWords*avgWordLength + n + m)
};