//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>>adj[n+1] ;
       
       for(auto it:edges){
           adj[it[0]].push_back({it[1],it[2]}) ;
           adj[it[1]].push_back({it[0],it[2]}) ;
       }
       
     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
     vector<int>dis(n+1,1e9);
     dis[1]=0;
     vector<int>parent(n+1) ;
     for(int i = 1 ; i<=n ; i++){
         parent[i] = i ;
     }
    pq.push({0,1}) ;
    while(!pq.empty()){
        auto it = pq.top() ;
       int node = it.second ;
       int dist = it.first ;
       pq.pop();
       
       for(auto it:adj[node]){
           int adjNode = it.first ;
           int edgeW = it.second ;
           if(dist+edgeW < dis[adjNode]){
               dis[adjNode] = dist + edgeW ;
               pq.push({dis[adjNode],adjNode}) ;
               parent[adjNode] = node ;
           }
           
       }
    }
    if(dis[n] == 1e9){
        return {-1} ;
    }
    vector<int> path ;
    int node = n ;
    while(parent[node]!=node){
        path.push_back(node) ;
        node = parent[node] ;
    }
    path.push_back(1) ;
    reverse(path.begin(),path.end()) ;
    return path ;
     }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends