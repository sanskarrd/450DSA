//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node ,vector<int>&vis , vector<vector<int>>& adj,stack<int>&st ){
	    vis[node] = 1 ;
	    for(auto it: adj[node]){
	        if(!vis[it])
	        dfs(it,vis,adj,st) ;
	    }
	    
	    st.push(node) ;
	}
	void dfs1(int index  , vector<int> &vis , vector<int>adjT[] ){
	    vis[index] = 1;
	    for(auto it : adjT[index]){
	        if(!vis[it]){
	            dfs1(it , vis , adjT);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int>vis(V,0) ;
        stack<int>st ;
        for(int i = 0 ; i<V ; i++){
            if(!vis[i]){
                dfs(i,vis,adj,st) ;
            }
        }
        
        vector<int>adjT[V] ;
        for(int i = 0 ; i<V ; i++){
            vis[i] = 0 ;
            for(auto it : adj[i]){
                adjT[it].push_back(i) ;
            }
        }
        int ans = 0 ;
        while(!st.empty()){
            int node = st.top() ;
            st.pop() ;
            if(!vis[node]){
                dfs1(node,vis,adjT) ;
                ans++ ;
            }
        }
        return ans ;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends