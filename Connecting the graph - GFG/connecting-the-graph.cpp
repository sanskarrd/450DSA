//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int node,vector<int>&vis, vector<int>adj[]){
      vis[node] = 1 ;
      for(auto it : adj[node]){
          if(!vis[it]){
              dfs(it,vis,adj) ;
          }
      }
  }
    int Solve(int n, vector<vector<int>>& edge) {
       
        if(edge.size() < n-1){
            return -1 ;
        }
        vector<int>adj[n] ;
        for(auto i : edge){
            adj[i[0]].push_back(i[1]) ;
             adj[i[1]].push_back(i[0]) ;
        }
        int ans = 0;
       vector<int>vis(n) ;
       for(int i = 0 ; i<n ; i++){
           if(!vis[i]){
               dfs(i,vis,adj) ;
               ans++ ;
           }
       }
    //   int ans = 0 ;
    //   for(int i = 0 ; i<n ; i++){
    //       if(vis[i] ==0){
    //           ans ++ ;
    //       }
    //   }
       return ans-1 ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends