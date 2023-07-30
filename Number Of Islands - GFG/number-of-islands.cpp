//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet{
private:
public:
    vector <int> parent,size;
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i = 1;i <= n;i++){
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u,int v){
        int up = findUPar(u);
        int vp = findUPar(v);
        if(up == vp) return;
        if(size[up] < size[vp]){
            parent[up] = vp;
            size[vp] += size[up];
        }
        else{
            parent[vp] = up;
            size[up] += size[vp];
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m) ;
        vector<int>ans ;
        vector<vector<int>>vis(n,vector<int>(m,0)) ;
        int cnt = 0 ;
        for(auto it : operators){
            int row = it[0] ;
            int col = it[1] ;
            if(vis[row][col]){
                ans.push_back(cnt) ;
                continue ;
            }
            vis[row][col] = 1 ;
            cnt++ ;
            
            int drow[] = {-1,0,1,0};
            int dcol[] = {0,1,0,-1};
            for(int i = 0 ; i<4 ; i++){
                int nrow = row+drow[i] ;
                int ncol = col+dcol[i] ;
                 
                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] == 1){
                     int nodeNo = row*m+col ;
                     int adjNode = nrow*m+ncol ;
                     if(ds.findUPar(nodeNo) != ds.findUPar(adjNode)){
                         cnt-- ;
                         ds.unionBySize(nodeNo,adjNode) ;
                     }
                 }
            }
            ans.push_back(cnt) ;
        }
        return ans ;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends