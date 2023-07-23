//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {

         int maxi = INT_MIN;
         priority_queue<pair<int, pair<int, int>>, 
                        vector<pair<int, pair<int, int>>>, 
                        greater<pair<int,pair<int, int>>>> minH;
                                                                            
         for(int i = 0 ; i< k ; i++){
             minH.push({arr[i][0],{i,0}}) ;                     
             maxi = max(maxi,arr[i][0]) ;
         }
         int left =INT_MAX ,right = INT_MAX ;
         int range = INT_MAX;
         while(true){
              int mini =   minH.top().first ;
              int ind1 = minH.top().second.first ;
              int ind2 = minH.top().second.second ;
              minH.pop() ;
              if(maxi-mini+1 <range){
                  range = maxi-mini+1 ;
                  left = mini ;
                  right= maxi ;
              }
              
              if(ind2 >=n-1){
                  break ;
              }
              minH.push({arr[ind1][ind2+1] , {ind1,ind2+1}}) ;
              maxi = max(maxi,arr[ind1][ind2+1]) ;
              
         }
         return {left,right} ;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends