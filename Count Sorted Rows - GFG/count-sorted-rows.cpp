//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int sortedCount(int N, int M, vector<vector<int>> Mat) {
        int count=0;
       for(int i=0; i<N; i++)
       {
          
           int dec=0;
           int inc=0;
           for(int j=0; j<M-1; j++)
           {
               if(Mat[i][j]> Mat[i][j+1]) 
               dec++;
               if(Mat[i][j]< Mat[i][j+1]) 
               inc++;
           }
           if(inc==M-1 || dec==M-1) 
           count++;
       }
       return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.sortedCount(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends