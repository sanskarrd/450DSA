//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
     void solve(vector<int> &A, int B,vector<int>&temp,vector<vector<int>>&ans,int i,int sum){
  if (sum == B) {
        ans.push_back(temp);
        return;
    }

    if (sum > B || i >= A.size()) {
        return;
    }

    for (int j = i; j < A.size(); j++) {
        // Skip duplicates
        if (j > i && A[j] == A[j - 1]) {
            continue;
        }

        sum += A[j];
        temp.push_back(A[j]);
        solve(A, B, temp, ans, j, sum);
        sum -= A[j];
        temp.pop_back();
    }

    sort(temp.begin(), temp.end());
 }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        vector<int>temp ;
        vector<vector<int>> ans ;
        int i=0 ,sum=0;
        sort(A.begin(),A.end()) ;
        solve(A,B,temp,ans,i,sum) ;
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
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends