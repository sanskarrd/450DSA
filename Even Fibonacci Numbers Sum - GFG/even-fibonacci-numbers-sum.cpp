//{ Driver Code Starts

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

class Solution{
public:
    long long evenFibSum(int N){
        // code here
        long long ans = 0 ;
        int a = 0 ;
        int b =1 ;
        int c =a+b ;
        while(c<=N){
            c= a+b;
            a=b ;
            b=c;
            if(c%2==0 && c<=N){
                ans +=c ;
            }
        }
       return ans ;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenFibSum(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends