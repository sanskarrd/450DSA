//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int row = grid.size() ;
        int col = grid[0].size() ;
        
        int vis[row][col] ;
        int cntFresh = 0 ;
        queue<pair<pair<int,int> , int > > q ;
        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ; j <col ; j++){
                
                if(grid[i][j] == 2){
                    q.push({{i,j} ,0}) ;
                    vis[i][j] = 2 ;
                }
                else{
                    vis[i][j] = 0 ;
                }
                if(grid[i][j] ==1)
                cntFresh++ ;
            }
        }
        int ans = 0 ;
        int drow[] = {-1,0,1,0} ;
        int dcol[] = {0,1,0,-1} ;
        int cnt = 0 ;
        while(!q.empty()){
            int i = q.front().first.first ;
            int j = q.front().first.second ;
            int tm = q.front().second ;
            ans = max(ans,tm) ;
            q.pop();
            
            for(int k = 0 ; k< 4 ;k++ ){
                int nrow = i+drow[k] ;
                int ncol = j+dcol[k] ;
                
                if(nrow>=0 && nrow<row && ncol>=0 && ncol<col 
                && vis[nrow][ncol] != 2 && grid[nrow][ncol] ==1){
                    q.push({{nrow,ncol},tm+1}) ;
                    vis[nrow][ncol] = 2 ;
                    cnt++ ;
                }
            }
        }
        if(cnt!=cntFresh){
            return -1 ;
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