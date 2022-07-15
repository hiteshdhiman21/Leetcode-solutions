void buildTree(vector<int> &tree, int start, int end, int treeNode){
    if(start == end){
        tree[treeNode] = 1;
        return;
    }
 
    int mid = (start+end)/2;
    buildTree(tree, start, mid, 2*treeNode);
    buildTree(tree, mid+1, end, 2*treeNode+1);
 
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}
 
void updateTree(vector<int> &tree, int start, int end, int treeNode, int idx){
    if(start == end){
        tree[treeNode] = 0;
        return;
    }
 
    int mid = (start+end)/2;
 
    if(idx <= mid){
        updateTree(tree, start, mid, 2*treeNode, idx);
    }else{
        updateTree(tree, mid+1, end, 2*treeNode+1, idx);
    }
 
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

int QueryOnTree(vector<int> &tree, int start, int end, int treeNode, int noFrees){
    //cout << start << " " << end << "          ";
    if(start == end){
        return start;
    }else if(start > end){
        return end;
    }
    
    int mid = (start+end)/2;
    
    //cout << treeNode << " " << tree[treeNode] <<  endl;
 
    if(tree[2*treeNode] > noFrees){
        return QueryOnTree(tree, start, mid, 2*treeNode, noFrees);
    }else {
        return QueryOnTree(tree, mid+1, end, 2*treeNode+1, noFrees-tree[2*treeNode]);
    }
}
 

class Solution {
public:
    
    static bool cmp(vector<int> &a, vector<int>&b)
    {
        if(a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), cmp);
        vector<int> tree(4*n+1);
        
        buildTree(tree, 0, n-1, 1);
        
        vector<vector<int>> res(n);
        
        for(int i=0; i<n; i++){
            cout << i <<" ";
            int h = people[i][0], k = people[i][1];
            int ind = QueryOnTree(tree, 0, n-1, 1, k);
            cout << ind  << endl;
            res[ind] = people[i];
            updateTree(tree, 0, n-1, 1, ind);
        }
        
        return res;
    }
};