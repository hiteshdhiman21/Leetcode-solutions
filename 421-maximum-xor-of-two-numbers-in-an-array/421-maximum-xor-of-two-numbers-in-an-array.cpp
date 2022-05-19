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
            if(!cur->containsKey(bit)) cur->put(bit);//endl
            cur = cur->get(bit);
        }
    }
    
    int findMax(int num){
        int ans = 0;
        Node *cur = root;
        for(int i=30; i>=0; i--){
            if(cur == NULL) return ans;
            
            bool bit = (num&(1<<i)); //We can also use ((num>>i)&(1)) to get in terms of 0 and 1 only 
            bool bestBit = !bit;
            if(cur->containsKey(bestBit)){   //If it contains best bit, go to it and set that bit in ans as 1.
                ans = (ans|(1<<i));
                cur = cur->get(bestBit);
            }else{  //Else just go to the same bit and do not set that bit in ans.
                cur = cur->get(bit);
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        //Step-1. Insert all the numbers(bit representations) from the array into the trie, starting from the leftmost bit.(32, 31, ......, 1)
        //Step-2. Then for each element of the array try to find the best num in the trie. i.e., for every bit of the element, try to go to the opposit bit elements in the trie if possible.
        Trie *t = new Trie;
        for(int i=0; i<nums.size(); i++) t->insert(nums[i]);
        
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            ans = max(ans, t->findMax(nums[i]));
        }
        
        return ans;
    }
    //T - 31n + 31n (as the nums[i] is have max 31 bit)
    //S - O(31n) (But it can only be in the worst case which is very rare)
};