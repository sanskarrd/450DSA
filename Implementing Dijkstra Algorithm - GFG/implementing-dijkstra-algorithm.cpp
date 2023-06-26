//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:

    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>> st ;
        vector<int>dis(V,1e9) ;
        
        st.insert({0,S}) ;
        dis[S] = 0 ;
        
        while(!st.empty()){
            auto it = *(st.begin()) ;
            int node = it.second ;
            int dist = it.first ;
            st.erase(it) ;
            
            for(auto it : adj[node]){
            int adjNode = it[0] ;
            int edgeW = it[1] ;
            
            if(dist + edgeW < dis[adjNode]){
                if(dis[adjNode]!=1e9)
                st.erase({dis[adjNode],adjNode}) ;
                dis[adjNode] = dist + edgeW ;
                st.insert({dis[adjNode] , adjNode}) ;
            }
        }
        }
        return dis ;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends