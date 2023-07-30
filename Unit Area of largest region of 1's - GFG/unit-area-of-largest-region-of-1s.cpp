//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>&vis,int& cnt){
        vis[r][c] =1 ;
        cnt++ ;
         int n = grid.size();
        int m = grid[0].size();
        for(int nr=-1 ; nr<=1 ; nr++){
            for(int nc = -1 ; nc<=1 ; nc++){
                if(r+nr>=0 && r+nr<n && c+nc>=0 && c+nc<m && vis[r+nr][c+nc] == 0 && grid[r+nr][c+nc])
                dfs(r+nr,c+nc,grid,vis,cnt);
            }
        }
    }
    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans =INT_MIN;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0 ; i< n ; i++){
            for(int j= 0 ; j< m ; j++){
                int cnt = 0 ;
                if(vis[i][j] == 0 && grid[i][j]){
                    dfs(i,j,grid,vis,cnt);
                    ans = max(ans,cnt) ;
                }
            }
        }
        return ans==INT_MIN?0:ans ;
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
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends