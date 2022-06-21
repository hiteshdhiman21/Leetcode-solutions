class Solution {
    
    unordered_map<string, vector<string>> m;
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(string &str: wordList){
            for(int i = 0; i< str.size(); i++){
                m[str.substr(0, i)+"*"+str.substr(i+1, str.size()-i-1)].push_back(str);
            }
        }
        
        queue<string> q;
        unordered_set<string> vis;
        q.push(beginWord);
        vis.insert(beginWord);
        int k = 1;
        
        while(!q.empty()){
            int qSize = q.size();
            for(int i = 0; i< qSize; i++){
                string cur = q.front(); q.pop();
                if(cur == endWord) return k;
                for(int i = 0; i< cur.size(); i++){
                    string xType = cur.substr(0, i)+"*"+cur.substr(i+1, cur.size()-i-1);
                    for(string &x: m[xType])
                        if(!vis.count(x)){
                            q.push(x); vis.insert(x);
                        }
                }
            }
            k++;
        }
        
        return 0;
    }
    //T - O(2*m*m*n) where n = no. of strings and m = avg length of each string
    //S - O(2*m*m*n)
};