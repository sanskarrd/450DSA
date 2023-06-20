//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& image, vector<vector<int>>&ans,vector<vector<int>>&vis, int newColor, int oldcolor ){
         int n = image.size() ;
         int m = image[0].size() ;

        if (i>=n ||  i<0||  j>=m || j<0 || vis[i][j] == 1  || ans[i][j] == newColor){
            return;
        }

        vis[i][j] = 1;

        if(image[i][j] ==  oldcolor){
        ans[i][j] = newColor;

        dfs(i-1,j,image,ans,vis,newColor,oldcolor);
        dfs(i+1,j,image,ans,vis,newColor,oldcolor);
        dfs(i,j-1,image,ans,vis,newColor,oldcolor);
        dfs(i,j+1,image,ans,vis,newColor,oldcolor);
        }
    }
    public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here
        int n = image.size() ;
        int m = image[0].size() ;
        vector<vector<int>>vis(n,vector<int>(m,0)) ;
        vector<vector<int>>ans = image; 
        int oldcolor= image[sr][sc] ;

        dfs(sr, sc, image, ans, vis, newColor, oldcolor);

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
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends