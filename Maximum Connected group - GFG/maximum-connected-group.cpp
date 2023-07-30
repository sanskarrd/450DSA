//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    public:
    vector<int>parent,size ;
    DisjointSet(int n){
        parent.resize(n+1) ;
        size.resize(n+1,1) ; 
        for(int i = 0 ; i<= n ; i++){
            parent[i] = i ;
        }
        
    }
        int findUPar(int node){
            if(node == parent[node]){
                return node ;
            }
            return parent[node] = findUPar(parent[node]) ;
        }
        
        void unionBySize(int u , int v){
            int ulpu = findUPar(u) ;
            int ulpv = findUPar(v) ;
            if(ulpu == ulpv) return  ;
            if(size[ulpu] < size[ulpv]){
                parent[ulpu] = ulpv ;
                size[ulpv] += size[ulpu] ;
            }
            else{
                 parent[ulpv] = ulpu ;
                size[ulpu] += size[ulpv] ;
            }
    }
    
};
class Solution {
  public:
  bool isValid(int newr, int newc, int n) {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size() ;
        
        
        DisjointSet ds(n*n) ;
        for(int row = 0; row< n ; row++ ){
            for(int col= 0 ; col< n ; col++){
                if(grid[row][col] == 0)continue ;
                
                int drow[]= {-1,0,1,0} ;
                int dcol[]= {0,-1,0,1} ;
                
                for(int ind = 0 ; ind< 4 ; ind++){
                    int nrow= row + drow[ind] ;
                    int ncol = col + dcol[ind] ;
                    if(isValid(nrow,ncol,n)){
                        if(grid[nrow][ncol] == 1){
                            int nodeNumber = row*n + col ;
                            int adjNode = nrow*n+ncol ;
                            ds.unionBySize(nodeNumber,adjNode) ;
                        }
                    }
                }
            }
        }
        
        int mx= 0 ;
        for(int row = 0 ; row< n ; row++){
            for(int col = 0 ; col< n ; col++){
                if(grid[row][col]==1)continue ;
                
                set<int>components ;
                int drow[]= {-1,0,1,0} ;
                int dcol[]= {0,-1,0,1} ;
                
                for(int ind = 0 ; ind< 4 ;ind++){
                    int nrow= row + drow[ind] ;
                    int ncol =col + dcol[ind] ;
                   if (isValid(nrow, ncol, n)) {
                        if (grid[nrow][ncol] == 1) {
                            components.insert(ds.findUPar(nrow * n + ncol));
                        }
                    }
                }
                int totalSum = 0 ;
                for(auto it: components){
                    totalSum += ds.size[it] ;
                }
                 mx = max(mx,totalSum+1) ;
            }
        }
        
        for(int node= 0 ; node<n*n ; node++ ){
            mx = max(mx,ds.size[ds.findUPar(node)]) ;
        }
        return mx ;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends