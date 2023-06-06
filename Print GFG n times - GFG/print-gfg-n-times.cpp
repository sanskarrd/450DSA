//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int printGFG(int N){
      if(N==0){
          return 0 ;
      }
      cout<<"GFG " ;
      N-- ;
      printGFG(N) ;
  }
    void printGfg(int N) {
        // Code here
        printGFG(N) ;
    }
};


//{ Driver Code Starts.
/* Driver program to test printNos */
int main() {
    int T;

    // taking testcases
    cin >> T;

    while (T--) {
        int N;

        // input N
        cin >> N;
        Solution ob;
        // calling printNos() function
        ob.printGfg(N);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends