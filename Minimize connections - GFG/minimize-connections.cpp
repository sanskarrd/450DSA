//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    void dfs(int node,vector<int>&vis, vector<int>adj[]){
      vis[node] = 1 ;
      for(auto it : adj[node]){
          if(!vis[it]){
              dfs(it,vis,adj) ;
          }
      }
  }
        int minimumConnections(int n , vector<vector<int>> &connections)
        {
              if(connections.size() < n-1){
            return -1 ;
        }
        vector<int>adj[n] ;
        for(auto i : connections){
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
   
       return ans-1 ;
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> connections(m,vector<int> (2));
        for(auto &j:connections)
            cin>>j[0]>>j[1];
        Solution s;
        cout<<s.minimumConnections(n,connections)<<endl;
    }
    return 0;
}
// } Driver Code Ends