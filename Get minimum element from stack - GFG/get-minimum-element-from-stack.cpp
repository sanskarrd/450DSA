//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    public:
    int mini ;
       /*returns min element from stack*/
       int getMin(){
           
           if(s.empty()){
               return -1 ;
           }
           else{
               return mini ;
           }
           //Write your code here
           
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
           if(s.empty()){
               return -1 ;
           }
           int cur = s.top() ;
           s.pop() ;
           if(cur> mini){
               return cur ;
           }
           else{
               int prevMin = mini ;
               int val = 2*mini - cur ;
               mini = val ;
               return prevMin ;
           }
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
           if(s.empty()){
               mini = x;
               s.push(x) ;
           }
           else{
               if(x<mini){
                   int val = 2*x - mini ;
                   mini = x ;
                   s.push(val) ;
               }
               else{
                   s.push(x) ;
               }
           }
           
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends