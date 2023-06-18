//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
          if(K==N) return K;
        int start=1, end=N;
        bool flag= true;
        while(start<=end){
            if(flag){
                start+=K;
                flag=false;
            }
            else {
                end-=K;
                flag=true;
            }  
        }
        if(!flag) return end;
        return start;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends