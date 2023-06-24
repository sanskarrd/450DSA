//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
       int n = S.size() ;
       vector<pair<pair<int,int>,int> > meet ;
       for(int i = 0 ; i<n ; i++){
           meet.push_back({{F[i],S[i]},i+1}) ;
       }
       
       sort(meet.begin(),meet.end()) ;
       vector<int> ans ;
       int lastMeetEnd = -1 ;
       for(int i = 0 ; i< n ; i++){
           if(meet[i].first.second > lastMeetEnd){
               ans.push_back(meet[i].second) ;
               lastMeetEnd = meet[i].first.first ;
           }
       }
      sort(ans.begin(),ans.end()) ;
       return ans ;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends