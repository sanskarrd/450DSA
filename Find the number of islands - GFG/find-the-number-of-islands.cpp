//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private :
    void bfs(int row,int col,vector<vector<int> > &vis,vector<vector<char>>& grid){
        vis[row][col] = 1 ;
        queue<pair<int,int> > q; 
        q.push({row,col}) ;
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        while(!q.empty()){
            int row = q.front().first ;
            int col = q.front().second ;
            q.pop() ;
            
            for(int delrow = -1 ; delrow<=1 ; delrow++){
                for(int delcol = -1 ;delcol<=1 ; delcol++){
                    
                    int nrow = row+delrow ;
                    int ncol = col+delcol ;
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol< m 
                    && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                        
                        vis[nrow][ncol] = 1 ;
                        q.push({nrow,ncol}) ;
                        
                    }
                }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int row = grid.size() ;
        int col = grid[0].size() ;
        int cnt = 0 ;
        vector<vector<int> > vis(row,vector<int> (col,0)) ;
        for(int i = 0 ; i< row ; i ++){
            for(int j = 0 ; j <col ; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++ ;
                    bfs(i,j,vis,grid) ;
                }
            }
        }
        return cnt ;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends