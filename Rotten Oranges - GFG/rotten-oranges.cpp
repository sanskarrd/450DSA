//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<pair<int,int>,int>> q ;
        int vis[n][m] ;
        for(int i = 0 ;i< n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0}) ;
                    vis[i][j] =2 ;
                }
                else{
                    vis[i][j] = 0 ;
                }
            }
        }
        int Time = 0 ;
        int drow[] = {-1,0,1,0} ;
        int dcol[] = {0,1,0,-1} ;
        while(!q.empty()){
            int a = q.front().first.first ;
            int b = q. front().first.second ;
            int tme =  q.front().second ;
            Time = max(Time,tme) ;
            q.pop();
            for(int i = 0 ; i< 4 ; i++){
                int nrow = a + drow[i] ;
                int ncol = b + dcol[i] ;
                if(nrow >=0 && nrow< n && ncol>=0 && ncol< m && vis[nrow][ncol]!=2 && grid[nrow][ncol] ==1){
                    q.push({{nrow,ncol},tme+1}) ;
                    vis[nrow][ncol] = 2 ;
                }
            }
        }
        
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j< m; j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    return -1 ;
                }
            }
        }
        
        return Time ;
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