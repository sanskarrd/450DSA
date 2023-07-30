//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
  int ans;
    int mod = (1e9+7) ;
    void solve(long long num, long long low, long long high) {
        if (num > high) {
            return;
        }

        if (num >= low && num <= high) {
            (ans++)%mod;
        }

        int lastDigit = num % 10;
        if (lastDigit == 9) {
            solve(num * 10 + 8, low, high);
        } else if (lastDigit == 0) {
            solve(num * 10 + 1, low, high);
        } else {
            solve(num * 10 + (lastDigit + 1), low, high);
            solve(num * 10 + (lastDigit - 1), low, high);
        }
    }
    int steppingNumbers(int a, int b)
    {
        ans = 0 ;

        if (a == 0) {
            ans++;
        }

        for (int i = 1; i <= 9; i++) {
            solve(i, a, b);
        }

        return ans%mod;
    }
};


//{ Driver Code Starts.

int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        Solution obj;
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends