class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        for(char ch1 = 'a'; ch1 <= 'z'; ch1++){
            for(char ch2 = 'a'; ch2 <='z'; ch2++){
                
                if(ch1 == ch2) continue;
                
                int var = 0;
                
                bool startAtch2 = false;
                bool containCh2 = false;
                for(auto ch:s){
                    if(ch==ch1){
                        var++;
                    }else if(ch == ch2){
                        if(!startAtch2)
                        var--;
                        containCh2 = true;
                        startAtch2 = false;
                    }
                    
                    if(var <= -1 && ch == ch2){
                        startAtch2 = true;
                        containCh2 = true;
                        var = -1;
                    } 
                    //if((ch1 == 'a' && ch2 == 'b') ||(ch1 == 'b' && ch2 == 'a') )
                    //cout << ch1 << " " << ch2 << " " << var << endl;
                    
                    if(containCh2)
                    ans = max(ans, var);
                }
            }
            
        }
        return ans;
    }
};