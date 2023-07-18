//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str1){
		    int n = str1.length() ;
           string str2 = str1 ;
           int arr[n+1][n+1] ;
           for(int i = 0 ; i <=n ; i++) 
           {
               for(int j =0 ; j<=n  ; j++)
               {
                   
                   if(i == 0 || j ==0)
                   arr[i][j] = 0 ;
                   else if (str1[i-1] == str2[j-1] && i!=j)
                   arr[i][j] = arr[i-1][j-1] +1 ;
                   else 
                   arr[i][j] = max(arr[i-1][j] , arr[i][j-1]) ;
               }
           }
           return arr[n][n] ;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends