//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
void checkPrime(int n ,vector<bool>&isPrime){
    isPrime[0] = false ;
    isPrime[1] = false ;
    for(int i = 2 ; i*i<=n; i++)
    {  
        if(isPrime[i] == true){
              for(int j = i*i ; j<=n ; j+=i){
            isPrime[j] = false ;
        }
           }
        }
      
}
    vector<int> primeDivision(int n){
    vector<bool>isPrime(n+1,true);
    checkPrime(n,isPrime);
       vector<int>temp;
        for(int i = 2 ; i<=n/2 ; i++){
            int a = i ;
            int complement = n-i ;
            if(isPrime[a] && isPrime[complement]){
                temp.push_back(a) ;
                temp.push_back(complement);
            }
        }
        return temp ;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}
// } Driver Code Ends