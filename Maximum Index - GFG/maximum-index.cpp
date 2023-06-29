//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // LMIN    = [34,8,8,3,2,2,2,2,2] 
    // RMAX    = [80,80,80,80,80,80,33,33,1]
    int maxIndexDiff(int arr[], int n) 
    { 
        vector<int>lMin(n) ;
        vector<int>rMax(n) ;
        lMin[0] =arr[0];
        for(int i= 1 ; i< n ; i++){
            lMin[i] = min(arr[i],lMin[i-1]) ;
        }
        rMax[n-1] = arr[n-1] ;
        for(int i = n-2 ; i>=0 ; i--){
             rMax[i] = max(arr[i],rMax[i+1]) ;
        }
        int ans = INT_MIN;
        int i = 0  , j = 0 ;
        while(i<n && j<n){
           if(lMin[i]<=rMax[j]){
               ans = max(ans ,(j-i)) ;
               j++ ;
           }
           else{
               i++;
           }
        }
        return ans ;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends