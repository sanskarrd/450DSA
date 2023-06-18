//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   bool isValid(int mid, int arr[], int n, int d) {
    int cnt = 1;  // Initialize cnt with 1 to account for the first day
    int currSum = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] > mid) {
            return false;  // If a weight exceeds mid, it is not valid
        }
        
        currSum += arr[i];
        
        if (currSum > mid) {
            cnt++;  // Increment cnt and start a new day
            currSum = arr[i];
        }
    }
    
    return cnt <= d;  // Return true if the number of days is less than or equal to d
}
    int leastWeightCapacity(int arr[], int N, int D) {
    
        int low = *min_element(arr,arr+N) ;
        int high = 0;
        for(int i = 0 ;i< N ;i++){
            high+=arr[i];
        }
        int ans  = 0;
        
        while(low<=high){
            int mid = low+(high-low) /2 ;
            
            if(isValid(mid,arr,N,D)){
                ans = mid ;
                high = mid -1 ;
            }
            else{
                low = mid+1 ;
            }
        }
        return ans  ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends