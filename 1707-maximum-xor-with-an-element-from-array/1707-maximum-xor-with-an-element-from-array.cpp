class Node{
    public:
    vector<Node*> links; //links[0] denotes unset, links[1] denotes set.
    
    Node(){
        links.resize(2, NULL);
    }
    
    Node* get(int& bit){
        return links[bit];
    }
    
    void put(int& bit){
        links[bit] = new Node;
    }
    
    bool containsKey(int& bit){
        return links[bit] != NULL;
    }
        
};

class Trie{
    public:
    Node *root;
    
    Trie(){
        this->root = new Node;
    }
    
    void insert(int& num){
        Node *cur = root;
        for(int i=30; i>=0; i--){
            int bit = ((num>>i)&1);
            if(!cur->containsKey(bit)) cur->put(bit);//endl
            cur = cur->get(bit);
        }
    }
    
    int findMax(int& num){
        int ans = 0;
        Node *cur = root;
        for(int i=30; i>=0; i--){
            
            int bit = ((num>>i)&(1)); //We can also use ((num>>i)&(1)) to get in terms of 0 and 1 only 
            int bestBit = 1-bit;
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



bool cmp(vector<int>& a, vector<int>& b){
    return a[1] < b[1]; //a[1] contains m1, b[1] contains m2l
}

class Solution {
public:
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        //OFFLINE Queries
        sort(nums.begin(), nums.end());
        for(int i=0; i<queries.size(); i++){
            queries[i].push_back(i);
        }
        
        Trie *t = new Trie;
        
        sort(queries.begin(), queries.end(), cmp);
        
        vector<int> ans(queries.size());
        int ind = 0;
        for(int i=0; i<queries.size(); i++){
            int xi = queries[i][0], mi = queries[i][1], queryInd = queries[i][2];
            while(ind < nums.size() && nums[ind] <= mi){
                t->insert(nums[ind]);
                ind++;
            }
            
            if(ind==0) ans[queryInd] = -1;
            else ans[queryInd] = t->findMax(xi);
        }
        
        return ans;
    }
    //T - 31n + 31n (as the nums[i] is have max 31 bit)
    //S - O(31n) (But it can only be in the worst case which is very rare)
    
};