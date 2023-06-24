//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        if(s.length() == 1){
            return 0 ;
        }
        int result  = 0 ;
        stack<int>st ;
        st.push(-1);
        for(int i = 0 ; i<s.length() ;i++){
            if(s[i] == '('){
                st.push(i) ;
            }
            else{
                st.pop() ;
                
                if(!st.empty()){
                    result  = max(result ,i - st.top()) ;
                }
                
                else {
                    st.push(i) ;
                }
            }
        }
        return result ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends