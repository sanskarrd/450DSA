//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
int drow[]= {-1,0,1,0} ;
int dcol[] ={0,1,0,-1} ;
class Solution{
    
    private:
    void dfs(int i , int j , vector<vector<int>> &vis,vector<vector<char>> &mat){
        
        int n = mat.size() ;
        int m = mat[0].size() ;
        vis[i][j] = 1 ;
        for(int k = 0 ; k< 4 ; k++){
            int nrow = i + drow[k] ;
            int ncol = j+  dcol[k] ;
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
            mat[nrow][ncol] == 'O' && !vis[nrow][ncol]){
                dfs(nrow,ncol,vis,mat) ;
            }
        }
        
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
       vector<vector<int>> vis(n,vector<int> (m,0)) ;
       //first row
       for(int j =0 ; j<m ; j++){
           if(!vis[0][j] && mat[0][j] == 'O'){
               dfs(0,j,vis,mat) ;
           }
              //last row
            if(!vis[n-1][j] && mat[n-1][j] == 'O'){
               dfs(n-1,j,vis,mat) ;
           }
       }

       //first col ;
        for(int i =0 ; i<n ; i++){
           if(!vis[i][0] && mat[i][0] == 'O'){
               dfs(i,0,vis,mat) ;
           }
           
           // last col
            if(!vis[i][m-1] && mat[i][m-1] == 'O'){
               dfs(i,m-1,vis,mat) ;
           }
        }
        
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j< m ; j++){
                
                if(!vis[i][j] && mat[i][j]=='O'){
                    mat[i][j] ='X' ;
                }
            }
        }
        
        return mat ;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends