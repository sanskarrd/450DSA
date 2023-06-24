//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int arr[], int n, int k)
    {
        vector<int>ans ; 
        sort(arr,arr+n) ;
        int count  = n ;
        int minCost = 0 ;
        for(int i = 0 ; i<n ; i++){
            if(count <=0){
                break ;
            }
            minCost+=arr[i] ;
            count-=(k+1) ;
        }
        ans.push_back(minCost) ;
        int maxCost = 0 ;
        count  = n ;
        for(int i = n-1; i>=0 ; i--){
              if(count <=0){
                break ;
            }
            maxCost+=arr[i] ;
            count-=(k+1) ;
        }
        ans.push_back(maxCost) ;
        return ans ;

    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends