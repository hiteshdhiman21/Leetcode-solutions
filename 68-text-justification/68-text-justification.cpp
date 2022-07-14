class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int i = 0;
        
        while(i<n){
            
            int cur = i;
            int curWidth = 0;
            while(cur < n && words[cur].size()+curWidth <= maxWidth)
                curWidth += words[cur++].size()+1;
            
            curWidth--; cur--;//To remove space after the last word
            int nWordsHere = cur-i+1;
            int betwSpace = (nWordsHere==1)?0:(maxWidth-curWidth)/(nWordsHere-1) + 1;
            int extraSpaces = (nWordsHere==1)?0:(maxWidth-curWidth)%(nWordsHere-1);
           // cout << i << " "<< cur << " " << curWidth << endl;
            res.push_back("");
            
            int last = cur;
            cur = i;
            if(last < n-1){
                while(cur <= last){
                    res.back() += words[cur++];
                    for(int i=0; i<betwSpace && res.back().size() < maxWidth; i++) res.back() += " ";
                    if(extraSpaces > 0 && res.back().size() < maxWidth){
                        res.back() += " ";
                        extraSpaces--;
                    }
                }
            }else{
                while(cur <= last){
                    res.back() += words[cur++];
                    if(res.back().size() < maxWidth)
                    res.back() += " ";
                } 
            }
            
            while(res.back().size() < maxWidth)
                res.back() += " ";
            cur--;
            i = cur+1;
        }
        
        return res;
    }
};