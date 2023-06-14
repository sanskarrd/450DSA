//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        
       vector<long long int>ans ;
       if(n==1){
           ans.push_back(1);
           return ans ;
       }
       long long int product = 1 ;
       int zeroCount  = 0 ;
       int zeroIndex = -1 ;
       
       for(int i = 0 ; i<n ; i++){
           if(nums[i]== 0){
               zeroCount++ ;
               zeroIndex = i ;
           }
           else
           product = product * nums[i] ;
       }
       //
       if(zeroCount>1){
           return vector<long long int>(n,0) ;
       }
       
       for(long long int i = 0 ; i< n ;i++){
           if(zeroCount == 1){
               ans.push_back((i==zeroIndex)? product : 0) ;
           }else
           ans.push_back(product/nums[i]) ;
       }
       return ans  ;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends