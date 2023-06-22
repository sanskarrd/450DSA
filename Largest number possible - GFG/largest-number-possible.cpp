//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
 string findLargest(int N, int s) {
    string ans = "";

    if (s == 0 && N > 1) {
        return "-1";  // Return -1 when s is 0 and N > 1
    }
    if (s > 9 * N) {
        return "-1";  // Return -1 when s is greater than the maximum possible sum
    }
    while (ans.size() < N) {
        if (s > 9) {
            ans += '9';
            s -= 9;
        } else {
            if (s == 0) {
                ans += '0';
            } else {
                ans += to_string(s);
                s = 0;
            }
        }
    }

    return ans;
}

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends