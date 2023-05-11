//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
  void solve(int i, int j, vector<vector<int>>& m, int n, vector<vector<bool>>& vis, string path, vector<string>& ans) {
    if (i == n-1 && j == n-1) {
        ans.push_back(path);
        return;
    }
    //D
    if (i+1 < n && !vis[i+1][j] && m[i+1][j] == 1) {
        vis[i][j] = true;
        solve(i+1, j, m, n, vis, path+"D", ans);
        vis[i][j] = false;
    }
    //L
    if (j-1 >= 0 && !vis[i][j-1] && m[i][j-1] == 1) {
        vis[i][j] = true;
        solve(i, j-1, m, n, vis, path+"L", ans);
        vis[i][j] = false;
    }
    //R
    if (j+1 < n && !vis[i][j+1] && m[i][j+1] == 1) {
        vis[i][j] = true;
        solve(i, j+1, m, n, vis, path+"R", ans);
        vis[i][j] = false;
    }
    //U
    if (i-1 >= 0 && !vis[i-1][j] && m[i-1][j] == 1) {
        vis[i][j] = true;
        solve(i-1, j, m, n, vis, path+"U", ans);
        vis[i][j] = false;
    }
}

vector<string> findPath(vector<vector<int>>& m, int n) {
    vector<string> ans;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    if (m[0][0] == 1) {
        solve(0, 0, m, n, vis, "", ans);
    }
    return ans;
}

};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends