class Solution {
public:
    int Find(vector<int> &parent, int v){
        if(parent[v] == v) return v;
        else return parent[v] = Find(parent, parent[v]);
    }
    
    bool Union(int v1, int v2, vector<int> &parent, vector<int> &rank){
        int p1 = Find(parent, v1), p2 = Find(parent, v2);
        if(p1 == p2) return false;
        
        if(rank[p1] < rank[p2]){
            parent[p1] = p2;
        }else if(rank[p2] < rank[p1]){
            parent[p2] = p1;
        }else{
            parent[p2] = p1;
            rank[p1]++;
        }
        return true;        
    }
    
    void make(vector<int> &parent, vector<int>& rank){
        for(int i = 0; i<parent.size(); i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1), rank(n+1);
        make(parent, rank);
        
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            if(!Union(edges[i][0], edges[i][1], parent, rank)){
                ans = edges[i];
                break;
            }                
        }
        
        return ans;
    }
    //T - O(n)
    //S - O(n)
};