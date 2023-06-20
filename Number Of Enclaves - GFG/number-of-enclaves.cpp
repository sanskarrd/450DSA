//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  private :
   void dfs(int i , int j , vector<vector<int>> &vis,vector<vector<int>> &grid){
        
        int n = grid.size() ;
        int m = grid[0].size() ;
        vis[i][j] = 1 ;
        int drow[]= {-1,0,1,0} ;
        int dcol[] ={0,1,0,-1} ;
        for(int k = 0 ; k< 4 ; k++){
            int nrow = i + drow[k] ;
            int ncol = j+  dcol[k] ;
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
            grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                dfs(nrow,ncol,vis,grid) ;
            }
        }
        
    }
     public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        int n = grid.size() ;
        int m= grid[0].size() ;
        
        vector<vector<int>> vis(n,vector<int> (m,0)) ;
        for(int j =0 ; j<m ; j++){
           if(!vis[0][j] && grid[0][j] == 1){
               dfs(0,j,vis,grid) ;
           }
              //last row
            if(!vis[n-1][j] && grid[n-1][j] == 1){
               dfs(n-1,j,vis,grid) ;
           }
       }
       
         for(int i =0 ; i<n ; i++){
             //first col
           if(!vis[i][0] && grid[i][0] == 1){
               dfs(i,0,vis,grid) ;
           }
           
           // last col
            if(!vis[i][m-1] && grid[i][m-1] == 1){
               dfs(i,m-1,vis,grid) ;
           }
        }
        int cnt = 0 ;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j< m ;j++){
                if(!vis[i][j]  && grid[i][j] == 1){
                    cnt++ ;
                }
            }
        }
        return cnt ;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends