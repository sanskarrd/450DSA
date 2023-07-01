//{ Driver Code Starts

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

class Solution{
public:
bool kDivisors(int num, int k) {
   int cnt  = 0;
   for (int i = 1; i <= sqrt(num); i++) {
        if (num % i == 0) {
            if (i * i == num) {
                cnt++;
            } else {
                cnt += 2;
            }
        }
    }
    if(cnt ==k){
        return true ;
    }
    else{
        return false ;
    }
}

int count(int A, int B, int N) {
    int count = 0;
    int k = N;
    for (int i = A; i <= B; i++) {
        if (kDivisors(i, k)) {
            count++;
        }
    }
    return count;
}
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,N;
        cin>>A>>B>>N;
        Solution ob;
        cout << ob.count(A,B,N) << endl;
    }
    return 0; 
}
// } Driver Code Ends