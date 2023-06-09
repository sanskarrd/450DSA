//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int row = grid.size() ;
	    int col = grid[0].size() ;
	    
	    vector<vector<int> > vis(row,vector<int> (col,0)) ;
	    vector<vector<int> > dis(row,vector<int>(col,0)) ;
	    queue<pair<pair<int,int>,int> > q ;
	    
	    for(int i = 0 ; i <row ; i++){
	        for(int j = 0 ; j<col ; j++){
	            
	            if(grid[i][j] == 1){
	                q.push({{i,j},0}) ;
	                vis[i][j] = 1 ;
	            }
	            else{
	                vis[i][j]= 0 ;
	            }
	        }
	    }
	    
	    int drow[] = {-1,0,1,0} ;
	    int dcol[] = {0,1,0,-1} ;
	    while(!q.empty()){
	        
	        int n = q.front().first.first ;
	        int m = q.front().first.second ;
	        int steps = q.front().second ;
	        q.pop() ;
	        dis[n][m] = steps ; 
	        
	        for(int i = 0 ; i<4 ;i++){
	            int nrow = n + drow[i] ;
	            int ncol = m + dcol[i] ; 
	            
	            if(nrow>=0 && nrow<row && ncol>=0 && ncol<col
	            && !vis[nrow][ncol] ){
	                
	                vis[nrow][ncol] = 1  ;
	                q.push({{nrow,ncol},steps+1}) ;
	            }
	        }
	        
	    }
	   
	   return dis ;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends