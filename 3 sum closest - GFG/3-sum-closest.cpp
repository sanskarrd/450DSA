//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int arr[], int n, int x)
    {
        
     int closest = INT_MAX;
      sort(arr,arr+n);
    for (int i = 0; i < n - 2; i++) {
        int st = i + 1;
        int end = n - 1;

        while (st < end) {
            int sum = arr[i] + arr[st] + arr[end];
            closest = (abs(x - sum) < abs(x - closest)) ? sum : closest;

            if (sum < x) {
                st++;
            } else {
                end--;
            }
        }
    }

    return closest;
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
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends