//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
 int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<pair<int, int>> adj[n];
    for (auto it : flights) {
        adj[it[0]].push_back({it[1], it[2]});
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> cost(n, vector<int>(k + 2, INT_MAX));

    pq.push({0, {src, 0}});
    cost[src][0] = 0;

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        int money = curr.first;
        int node = curr.second.first;
        int stops = curr.second.second;

        if (node == dst) {
            return money;
        }

        if (stops > k) {
            continue;
        }

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int paisa = it.second;

            if (money + paisa < cost[adjNode][stops + 1]) {
                cost[adjNode][stops + 1] = money + paisa;
                pq.push({money + paisa, {adjNode, stops + 1}});
            }
        }
    }

    return -1;
}

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends