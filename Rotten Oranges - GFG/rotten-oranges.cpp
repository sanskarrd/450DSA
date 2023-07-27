//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        int vis[n][m] ;
        queue<pair<pair<int,int>,int>> q ;
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j< m ; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0}) ;
                    vis[i][j] = 2 ;
                }
                else{
                    vis[i][j] = 0 ;
                }
            }
        }
        int drow[4] = {-1,0,1,0} ;
        int dcol[4] = {0,1,0,-1} ;
        int ans = 0 ;
        while(!q.empty()){
            int row = q.front().first.first ;
            int col = q.front().first.second ;
            int time_  = q.front().second ;
            q.pop() ;
            
            ans  = max(ans,time_) ;
            for(int i = 0 ; i< 4 ; i++){
                int nrow = row+drow[i] ;
                int ncol = col+dcol[i] ;
                
                if(nrow>=0 && nrow<n && ncol>=0 && 
                ncol<m && grid[nrow][ncol] == 1 && vis[nrow][ncol]!=2){
                    vis[nrow][ncol] = 2 ;
                    q.push({{nrow,ncol} ,time_ + 1}) ;
                }
            }
            
        }
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j< m ; j++){
                if(grid[i][j] ==1 && vis[i][j] !=2){
                    return -1 ;
                }
            }
        }
        return ans ;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends