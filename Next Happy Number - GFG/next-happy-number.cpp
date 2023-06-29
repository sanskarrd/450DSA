//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
int isHappy(int num ){
    if(num==1 || num == 7){
        return 1 ;
    }
    else if(num<10){
        return 0 ;
    }
    int sum = 0 ;
    while(num){
        int digit = num%10 ;
        digit = digit* digit;
        num = num/10 ;
        sum += digit ;
    }
    isHappy(sum) ;
}
    int nextHappy(int N){
        for(int  i = N+1 ; i<INT_MAX ; i++){
            if(isHappy(i)){
                return i ;
            }
        }
        return -1 ;
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
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends