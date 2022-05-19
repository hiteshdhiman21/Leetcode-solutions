class Node{
    public:
    vector<Node*> links; //links[0] denotes unset, links[1] denotes set.
    
    Node(){
        links.resize(2, NULL);
    }
    
    Node* get(int bit){
        return links[bit];
    }
    
    void put(int bit){
        links[bit] = new Node;
    }
    
    bool containsKey(int bit){
        return links[bit] != NULL;
    }
        
};

class Trie{
    public:
    Node *root;
    
    Trie(){
        this->root = new Node;
    }
    
    void insert(int num){
        Node *cur = root;
        for(int i=30; i>=0; i--){
            bool bit = (num&(1<<i));
            if(!cur->containsKey(bit)){
                cur->put(bit);
            }
            cur = cur->get(bit);
        }
    }
    
    int findMax(int num){
        int ans = 0;
        Node *cur = root;
        for(int i=30; i>=0; i--){
            
            if(cur == NULL) return ans;
            
            bool bit = (num&(1<<i));
            bool findBit = !bit;
            if(cur->containsKey(findBit)){
                ans = (ans|(1<<i));
                cur = cur->get(findBit);
            }else{
                cur = cur->get(bit);
            }
        }
        
        return ans;
    }
    
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *t = new Trie;
        for(int i=0; i<nums.size(); i++) t->insert(nums[i]);
        
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans = max(ans, t->findMax(nums[i]));
        }
        
        return ans;
    }
};