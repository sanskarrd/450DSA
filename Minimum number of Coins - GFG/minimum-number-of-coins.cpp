//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
//   int solve(int n , vector<int>& cur,vector<int>&ans,vector<int>&dp){
//         if(n==0){
//             return 0;
//         }
//         if(dp[n]!=-1){
//             return dp[n];
//         }
//         int mini = INT_MAX ;
//         for(int i = 0 ; i<cur.size() ; i++){
//             if(cur[i]<=n){
//                  mini  = min(mini,1+solve(n-cur[i],cur,ans,dp));
//             // ans.push_back(cur[i]);
//             }
           
//         }
        
//         dp[n] = mini ;
//         return dp[n] ;
//     }
    vector<int> minPartition(int n)
    {
        vector<int>cur = {2000,500,200,100,50,20,10,5,2,1};
        vector<int>ans ;
        // int maxDen = 1 ;
       for(int i = 0 ; i<cur.size() ; i++){
           if(cur[i]<=n){
               int temp = cur[i] ;
               int notes = n/cur[i] ;
               for(int i = 0 ;i<notes;i++){
                   ans.push_back(temp) ;
               }
               n = n%cur[i] ;
           }
       }
       return ans ;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends