//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
             int n = s.length() ; 
             int dots = 0 ;
             for(int i = 1 ;i< n ; i++){
                 if(s[i] == s[i-1]  && s[i] == '.'){
                     return 0 ;
                 }
                 if(s[i] == '.'){
                     dots ++ ;
                 }
             }
             
             if(dots >3 || dots< 3){
                 return  0 ;
             }
             
             //leading 0;s
              if(s[0] == '0' && s[1]!='.' ) return 0;

             for(int i = 0 ; i< n ; i++){
                 while(s[i] != '.'  && i<n){
                     i++ ;
                 }
                 if(s[i+1] == '0' && s[i+2]!='.' && i+2<n){
                     return  0 ;
                 }
             }
             // nos
             for(int i=n-1;i>=0;i--){
                if(s[i]>='a' && s[i]<='z') return 0;
                
                int digit = 0;
                int mul = 1;
                while(s[i] != '.' && i>=0){
                    digit += mul * (s[i] - '0');
                    
                    mul *= 10;
                    i--;
                }
                
                if(digit<0 || digit>255)
                return 0;
                
            }
            return 1 ;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends