//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int arr[], int n, int k)
    {
    int ans = 0;
    int sum = 0;
    unordered_map<int, int> mp;
    mp[0] = 1; // Initialize with 1 to account for the case when the whole subarray has the sum 'k'
    
    for (int j = 0; j < n; j++) {
        sum += arr[j];
        int target = sum - k;
        if (mp.find(target) != mp.end()) {
            ans += mp[target];
        }
        mp[sum]++;
    }
    
    return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends