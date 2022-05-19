// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution{
    
	public:

		vector<string> AllPossibleStrings(string s){
		    string cur = "";
		    vector<string> ans;
		    int n = s.size();
		    
		    for(int num =0; num < (1<<n); num++){
		        string cur = "";
		        for(int ind=0; ind < n; ind++){
		            if(num &(1<<ind)) cur += s[ind];
		        }
		        if(cur.size() > 0)
		        ans.push_back(cur);
		    }
		    sort(ans.begin(), ans.end());
		    return ans;
		    
		    //T - n*(2^n)
		    //S - O(1)
		}
};



// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends