//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
    vector<int> leftSmaller(int n, int a[]){
        // code here
        stack<int> s ;
        vector<int> ans(n) ;
        s.push(-1) ;
        for(int i = 0 ; i<n ; i++){
            
            while( s.top()!= -1 && a[s.top()]>=a[i]){
                s.pop() ;
            }
            if(s.empty()){
                ans[i] = -1 ;
            }
            else{
                ans[i] = s.top()  ;
                s.push(i) ;
            }
        }
        return ans ;
    }
    
    
     vector<int> rightSmaller(int n, int a[]){
        // code here
        stack<int> s ;
        vector<int> ans2(n) ;
        s.push(-1) ;
        for(int i = n-1; i>=0 ; i--){
            
            while( s.top() != -1 && a[s.top()]>=a[i]){
                s.pop() ;
            }
            if(s.empty()){
                ans2[i] = -1 ;
            }
            else{
                ans2[i] = s.top() ;
                s.push(i) ;
            }
        }
        return ans2 ;
    }
    
    
    int getMaxArea(int arr[], int n)
    {
        // Your code here 
        int area ;
        area = INT_MIN ;
        vector<int>l = leftSmaller(n,arr) ;
        
        vector<int>r = rightSmaller(n,arr);
        
        for(int i = 0 ; i < n ; i++){
            int len  = arr[i] ;
            
           
            if(r[i] == -1){
                r[i] = n;
            }
            int width = r[i] - l[i] - 1  ;
            int currArea = len * width ;
            
            area = max(area,currArea) ;
        }
        
        return area ;
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int ans = getMaxArea(M[0],m) ;
        for(int i=1 ; i<n;i++){
            for(int j=0;j<m ;j++){
                if(M[i][j]!=0){
                    M[i][j] += M[i-1][j]  ;
                }
                else{
                    M[i][j] = 0 ;
                }
            }
            ans = max(ans,getMaxArea(M[i],m));
        }
        return ans ;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends