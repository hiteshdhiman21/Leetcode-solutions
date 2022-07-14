class Solution {
public:
    
    pair<int, int> findLast(vector<string>& words, int& maxWidth, int& i){
        int last = i;
        int curWidth = 0;
        while(last < words.size() && words[last].size()+curWidth <= maxWidth)
            curWidth += words[last++].size()+1;

        curWidth--; last--;//To remove space after the last word
        return {last, curWidth};
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int i = 0;
        
        while(i<n){
            
            auto [last, curWidth] = findLast(words, maxWidth, i);
          
            int nWordsHere = last-i+1;
            int betwSpace = (nWordsHere==1)?0:(maxWidth-curWidth)/(nWordsHere-1) + 1;
            int extraSpaces = (nWordsHere==1)?0:(maxWidth-curWidth)%(nWordsHere-1);
          
            res.push_back("");
            int cur = i;
            
            if(last < n-1){ //If it is not last line
                while(cur <= last){
                    res.back() += words[cur++];
                    for(int i=0; i<betwSpace && res.back().size() < maxWidth; i++) res.back() += " ";
                    if(extraSpaces > 0 && res.back().size() < maxWidth){
                        res.back() += " ";
                        extraSpaces--;
                    }
                }
            }else{ //If it is a last line
                while(cur <= last){
                    res.back() += words[cur++];
                    if(res.back().size() < maxWidth)
                    res.back() += " ";
                } 
            }
            
            while(res.back().size() < maxWidth)
                res.back() += " ";
            i = last+1;
        }
        
        return res;
    }
};