class Solution {
public:
    
    int Find(vector<int> &parent, int v){
        if(parent[v] == v) return v;
        else return parent[v] = Find(parent, parent[v]);
    }
    
    void Union(int v1, int v2, vector<int> &parent, vector<int> &rank){
        int p1 = Find(parent, v1), p2 = Find(parent, v2);
        if(p1 == p2) return;
        
        if(rank[p1] < rank[p2]){
            parent[p1] = p2;
        }else if(rank[p2] < rank[p1]){
            parent[p2] = p1;
        }else{
            parent[p2] = p1;
            rank[p1]++;
        }
        
    }
    
    void make(vector<int> &parent, vector<int>& rank){
        for(int i = 0; i<parent.size(); i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    static bool comp(vector<int> &a, vector<int> &b){
        return a[2] < b[2];
    }
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        for(int i = 0; i < queries.size(); i++){
            queries[i].push_back(i);
        }
        
        sort(edgeList.begin(), edgeList.end(), comp);
        sort(queries.begin(), queries.end(), comp);
        
        vector<int> parent(n);
        vector<int> rank(n);
        make(parent, rank);
        
        vector<bool> res(queries.size());
        int edgeInd = 0;
        for(int i = 0; i<queries.size(); i++){
            while(edgeInd < edgeList.size() && edgeList[edgeInd][2] < queries[i][2]){
                Union(edgeList[edgeInd][0], edgeList[edgeInd][1], parent, rank);
                edgeInd++;
            }
            
            if(Find(parent, queries[i][0]) == Find(parent, queries[i][1]))
                res[queries[i][3]] = true;
            else
                res[queries[i][3]] = false;
        }
        
        return res;
    }
    //T - O(qlogq + eloge + q + e + v)
    //S - O(v)
};