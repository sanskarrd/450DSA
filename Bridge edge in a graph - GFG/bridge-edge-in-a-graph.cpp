//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    int check(int c, int d, vector<int>adj[] , vector<int>&vis){
        if(c==d){
            return true ;
        }
        vis[c] = 1 ;
        for(auto it : adj[c]){
            if(!vis[it]){
                if(check(it,d,adj,vis)){
                    return true ;
                }
            }
        }
        return false ;
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<int>temp;
        for(auto i : adj[c]){
            if(i ==d)
            continue ;
            temp.push_back(i) ;
        }
        
        adj[c] = temp ;
        vector<int>vis(V,0) ;
        if(check(c,d,adj,vis)){
            return 0 ;
        }
        return 1 ;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends