//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    void dfs(int r,int c,  vector<vector<int>>&vis , vector<vector<char>>& grid){
        vis[r][c] = 1 ;
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        
        int drow[] = {-1,0,1,0} ;
        int dcol[] = {0,1,0,-1} ;
        
        for(int i = 0 ; i<4 ; i++){
            int nrow = r + drow[i] ;
            int ncol = c + dcol[i] ;
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
            grid[nrow][ncol] == 'X' && vis[nrow][ncol] == 0){
                dfs(nrow,ncol,vis,grid) ;
            }
        }
    }
    int xShape(vector<vector<char>>& grid) 
    {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<int>>vis(n,vector<int>(m,0)) ;
        int shapes = 0 ;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j] == 'O' )continue ;
                if(vis[i][j] == 0 && grid[i][j] == 'X'){
                    shapes++ ;
                    dfs(i,j,vis,grid) ;
                }
            }
        }
        return shapes ;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends