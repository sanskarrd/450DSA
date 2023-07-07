//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
 
    int minimumCostPath(vector<vector<int>>& grid) 
    {
         int n = grid.size() ;
         int m = grid[0].size() ;
         vector<vector<int>>dis(n,vector<int>(m,1e9)) ;
         priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
         dis[0][0] = grid[0][0];
         pq.push({grid[0][0],{0,0}}) ;
         
         int drow[4] = {-1,0,1,0} ;
         int dcol[4] = {0,1,0,-1} ;
         while(!pq.empty()){
             int row = pq.top().second.first ;
             int col = pq.top().second.second ;
             int cost = pq.top().first ;
             pq.pop() ;
             
             for(int i = 0 ; i<4 ; i++){
                 int nrow = row + drow[i];
                 int ncol = col+ dcol[i] ;
                 
                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                     if(cost+grid[nrow][ncol] < dis[nrow][ncol]){
                         dis[nrow][ncol] = cost + grid[nrow][ncol];
                         pq.push({cost + grid[nrow][ncol],{nrow,ncol}}) ;
                     }
                 }
             }
             
         }
         return dis[n-1][m-1] ;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends