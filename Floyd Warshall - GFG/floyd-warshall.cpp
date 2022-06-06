// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>& dist){
	    int V = dist.size();
	    
	    for(int w = 0; w<V; w++){
	        for(int u = 0; u < V; u++){
	            for(int v = 0; v < V; v++){
	                if(dist[u][w] != -1 && dist[w][v] != -1 && (dist[u][v] == -1 || dist[u][v] > dist[u][w]+dist[w][v]))
	                    dist[u][v] = dist[u][w]+dist[w][v];
	            }
	        }
	    }
	    
	}
	//T - O(V^3)
	//S - O(1)
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends