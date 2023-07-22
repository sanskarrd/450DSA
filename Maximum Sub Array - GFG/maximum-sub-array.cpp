//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    vector<int>ans, currDabba;
        int ansSum=0, currSum=0;
        
        for(int i=0; i<n; i++)
        {
            if(a[i]>=0)
            {
                currSum += a[i];
                currDabba.push_back(a[i]);
            }
            else{
                if(currSum > ansSum)
                {
                    ansSum = currSum;
                    ans = currDabba;
                    currDabba.clear();
                    currSum = 0;
                }
                else if(currSum==ansSum)
                {
                    ans = ans.size()>=currDabba.size() ? ans : currDabba;
                    currDabba.clear();
                    currSum = 0;
                }
                else{
                    currDabba.clear();
                    currSum = 0;
                }
            }
        }
        
        if(currSum > ansSum) ans = currDabba;
        else if(currSum==ansSum)
        {
            ans = ans.size()>=currDabba.size() ? ans : currDabba;
        }
        return ans;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends