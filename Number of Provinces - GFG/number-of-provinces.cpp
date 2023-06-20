//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    private:
    void dfs( vector<int>&vis,vector<int>adj[] , int node){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(vis,adj ,it) ;
            }
        }
    }
    public:
    int numProvinces(vector<vector<int>> adjL, int v) {
    
        vector<int>adj[v] ;
        for(int i = 0 ; i< v; i++){
            for(int j = 0 ; j< v ; j++){
                if(adjL[i][j]){
                    adj[i].push_back(j) ;
                    adj[j].push_back(i) ;
                }
            }
        }
        
        int cnt  = 0 ;
        vector<int>vis(v,0) ;
        for(int i = 0 ; i< v ;i++){
            if(!vis[i]){
                dfs(vis,adj,i) ;
                cnt++ ;
            }
        }
        return cnt ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends