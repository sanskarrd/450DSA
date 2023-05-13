//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
void insertAtBottom(stack<int> &St,int num){
    if(St.empty()){
        St.push(num) ;
        return;
    }
    int n = St.top();
    St.pop() ;
    insertAtBottom(St,num);
    St.push(n) ;
}
    void Reverse(stack<int> &St){
        if(St.empty()){
            return ;
        }
        int num = St.top() ;
        St.pop() ;
        Reverse(St) ;
        insertAtBottom(St,num);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends