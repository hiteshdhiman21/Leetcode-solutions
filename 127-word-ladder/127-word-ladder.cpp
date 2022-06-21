class Solution {
    
    unordered_map<string, vector<int>> m;
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      /*Step-1. First construct a map of the type for each string. 
                {{"*ot": hot, got}, {"h*t": hot, hit}, {"ho*": hot, hog}}
                First element is just typeOfString(mask), second element is a vector of all strings of type "typeOfString".
        Step-2. Use Biderectional-BFS to find the shortest path to endWord. To find adjacent words for each word we will use the above map.
        Step-3. For each string use strategy of prefSubstring + "*" + suffSubstring to construct mask.*/
        bool isEndWordPresent = false;
        for(int ind =0; ind<wordList.size(); ind++){
            string str = wordList[ind];
            for(int i = 0; i< str.size(); i++){
                m[str.substr(0, i)+"*"+str.substr(i+1, str.size()-i-1)].push_back(ind);
            }
            if(str == endWord)
                isEndWordPresent = true;
        }
        
        if(!isEndWordPresent) return 0;
        
        queue<string> q1, q2;
        unordered_map<string, int> vis1;
        q1.push(beginWord);
        unordered_map<string, int> vis2;
        q2.push(endWord);
        vis1[beginWord] =1;
        vis2[endWord] = 1;
        int k = 1;
        
        while(!q1.empty() && !q2.empty()){
           
            int q1Size = q1.size();
            for(int node = 0; node<q1Size; node++){ //Explore all same level nodes and look for node explored from the end
                string cur = q1.front(); q1.pop();
                for(int i = 0; i< cur.size(); i++){
                    string xType = cur.substr(0, i)+"*"+cur.substr(i+1, cur.size()-i-1);
                    for(int ind: m[xType]){

                        if(vis2.count(wordList[ind])){
                            return vis1[cur]+vis2[wordList[ind]];
                        }

                        if(!vis1.count(wordList[ind])){
                            q1.push(wordList[ind]); vis1[wordList[ind]] = vis1[cur]+1;
                        }
                    }
                }
            }
            
            int q2Size = q2.size();
            for(int node = 0; node<q2Size; node++){
                string cur = q2.front(); q2.pop();
                for(int i = 0; i< cur.size(); i++){ //Explore all same level nodes and look for node explored from the start
                    string xType = cur.substr(0, i)+"*"+cur.substr(i+1, cur.size()-i-1);
                    for(int ind: m[xType]){

                        if(vis1.count(wordList[ind])){
                            return vis2[cur]+vis1[wordList[ind]];
                        }

                        if(!vis2.count(wordList[ind])){
                            q2.push(wordList[ind]); vis2[wordList[ind]] = vis2[cur]+1;
                        }
                    }
                }
            }
            
        }
        
        return 0;
    }
    //T - O(2*m*m*n) where n = no. of strings and m = avg length of each string
    //S - O(2*m*m*n)
};