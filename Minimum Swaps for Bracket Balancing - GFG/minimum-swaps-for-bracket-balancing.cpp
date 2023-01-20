//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
   int openBrackets = 0;
        int closeBrackets = 0;
        int ans = 0;
        for(auto &e : S){
            if(e == ']'){
                closeBrackets++;
            }
            else{
                if(closeBrackets > openBrackets){
                    ans += closeBrackets - openBrackets;
                }
                openBrackets++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
} 
// } Driver Code Ends