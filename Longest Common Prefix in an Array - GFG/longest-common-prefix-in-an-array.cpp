//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
       sort(arr,arr+N);
       string s="";
       string f=arr[0];
       string e=arr[N-1];
       int k = min(f.length(),e.length()) ;
       
       for(int i=0;i<k;i++){
           if(arr[0][i]==arr[N-1][i]){
               s=s+arr[0][i];
           }
        
           else{
               break;
           }
       }
       if(s[0]!=e[0]){
           return "-1";
       }
       else{
           return s;
    }
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends