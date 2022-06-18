class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLength = 0;
        for(char ch = 'A'; ch <= 'Z'; ch++){
            deque<int> dq;
            int start = 0;
            for(int i = 0; i < s.size(); i++){
                if(s[i] != ch){
                    dq.push_back(i);
                }
                
                if(dq.size()>k){
                    start = dq.front()+1;
                    dq.pop_front();
                }
                
                maxLength = max(maxLength, i-start+1);
            }
            
        }
        
        return maxLength;
    }
    //T - O(26n)
    //S - O(k)
};