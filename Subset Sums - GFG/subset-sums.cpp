//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
     void Sol(int ind , int sum ,vector <int> &arr ,int N , vector<int> &ans)
    {
        if(ind==N)
        {
            ans.push_back(sum) ;
            return ;
        }
        Sol(ind+1,sum+arr[ind] , arr,N,ans) ;
        
        Sol(ind+1,sum ,arr,N,ans) ;
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector <int> ans ;
        Sol(0,0,arr,N,ans) ;
        sort(ans.begin(),ans.end()) ;
        return ans ;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends