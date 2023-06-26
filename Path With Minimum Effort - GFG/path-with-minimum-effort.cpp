//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   int MinimumEffort(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
    dis[0][0] = 0;
    pq.push({0, {0, 0}});
    
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        
        int row = it.second.first;
        int col = it.second.second;
        int heightDif = it.first;
        
        if (row == n - 1 && col == m - 1) {
            return heightDif; // Return the height difference at the destination cell
        }
        
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                max(heightDif, abs(heights[row][col] - heights[nrow][ncol])) < dis[nrow][ncol]) {
                dis[nrow][ncol] = max(heightDif, abs(heights[row][col] - heights[nrow][ncol]));
                pq.push({dis[nrow][ncol], {nrow, ncol}});
            }
        }
    }
    
    return 0; // Return 0 if no valid path is found
}

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends