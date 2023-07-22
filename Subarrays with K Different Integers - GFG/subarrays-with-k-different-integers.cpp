//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     int find(vector<int> &arr, int N, int k,int maxi){
        int j = 0 ,ans = 0 ;
        vector<int> v (maxi,0);
        int count = 0;
        for(int i = 0 ;i<N;i++)
        {
            v[arr[i]]++;
            if(v[arr[i]]==1) count++; 
            while(count>k)
            {
                v[arr[j]]--;
                if(v[arr[j]]==0) count--;
                j++;
            }
            
            ans += i-j+1;
        }
        return ans;
    }
  
    int subarrayCount(vector<int> &arr, int N, int k) {
         int maxim = 0;
        for(int  i = 0 ; i< N ;i++)
        {
            maxim = max(maxim,arr[i]);
        }
        return find(arr,N,k,maxim+1)-find(arr,N,k-1, maxim+1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayCount(arr, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends