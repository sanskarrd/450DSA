//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold)
    {
        
        vector<vector<int>> matrix(n,vector<int>(n,1e9)) ;
        
        for(auto it: edges){
            matrix[it[0]][it[1]] = it[2] ;
            matrix[it[1]][it[0]] = it[2] ;
        }
        
        for(int i = 0 ; i< n ; i++)   {
            matrix[i][i] = 0 ;
        } 
        
        for(int k = 0 ; k< n ; k++){
            for(int i = 0 ; i< n ; i++){
                for(int j = 0 ; j< n ; j++){
                    matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]) ;
                }
            }
        }
        
        int minCities = 1e9 ;
        int city  ;
        
        for(int i = 0 ; i< n ; i++){
               int cnt  = 0 ;
               for(int j = 0 ; j< n ; j++){
                   if(matrix[i][j] <= distanceThreshold){
                       cnt ++ ;
                   }
               }
              
               if(cnt<=minCities){
                   minCities = cnt ;
                   city = i ;
               }
        }
        return city ;
     }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends