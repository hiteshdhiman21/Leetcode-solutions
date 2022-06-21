class Solution {
    
    unordered_map<string, vector<int>> m;
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      /*Step-1. First construct a map of the type for each string. 
                {{"*ot": hot, got}, {"h*t": hot, hit}, {"ho*": hot, hog}}
                First element is just typeOfString(mask), second element is a vector of all strings of type "typeOfString".
        Step-2. Use BFS to find the shortest path to endWord. To find adjacent words for each word we will use the above map.
        Step-3. For each string use strategy of prefSubstring + "*" + suffSubstring to construct mask.*/
        
        for(int ind =0; ind<wordList.size(); ind++){
            string str = wordList[ind];
            for(int i = 0; i< str.size(); i++){
                m[str.substr(0, i)+"*"+str.substr(i+1, str.size()-i-1)].push_back(ind);
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
                    for(int ind: m[xType])
                        if(!vis.count(wordList[ind])){
                            q.push(wordList[ind]); vis.insert(wordList[ind]);
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