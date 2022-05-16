// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool isSafe(bool graph[101][101], int cur, int color, vector<int>& colorOf, int n){
    for(int nb = 0; nb < n; nb++){
        if(nb != cur && graph[cur][nb] && colorOf[nb] == color) return false;
    }
    return true;
}

bool isAllColored(bool graph[101][101], int m, int n, int cur, vector<int>& colorOf){
    if(cur == n) return true;
    
    for(int color=1; color<=m; color++){
        if(!isSafe(graph, cur, color, colorOf, n)) continue;
        
        colorOf[cur] = color;
        if(isAllColored(graph, m, n, cur+1, colorOf)) return true;
        colorOf[cur] = 0;
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> colorOf(n+1, 0);
    return isAllColored(graph, m, n, 0, colorOf);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends