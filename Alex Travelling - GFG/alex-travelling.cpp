//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        vector<pair<int,pair<int,int>>>adj[n+1] ;
        for(auto it: flights){
            adj[it[0]].push_back(make_pair(it[1], make_pair(it[2], 0)));
        }
        
        vector<int>dis(n+1,1e9) ;
        dis[k]= 0;
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
       pq.push(make_pair(0, k));

        
        while(!pq.empty())
        {
            int node = pq.top().second ;
            int cost = pq.top().first ;
            pq.pop() ;
            
            for(auto it:adj[node]){
                int adjN = it.first ;
                int adjC = it.second.first ;
                
                if(cost+adjC<dis[adjN]){
                    dis[adjN]= cost+adjC ;
                   pq.push(make_pair(cost + adjC, adjN));
                }
            }
        }
        
       for(int i = 1 ;i<= n ; i++){
           if(dis[i]  == 1e9){
               return -1 ;
           }
       }
       int ans = INT_MIN ;
       for(int i = 1 ; i<= n ; i++){
           ans  = max(ans,dis[i]) ;
       }
       
       return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends