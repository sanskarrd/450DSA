//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int n = nums.size() ;
        int xoR = 0  ;
        for(int i = 0 ; i< n ; i++){
            xoR = xoR^nums[i] ;
        }
        
        int cnt  = 0 ;
        while (xoR!=0){
            if(xoR&1==1){
                break ;
            }
            xoR = xoR>>1 ;
            cnt++ ;
        }
        
        int xoR1 = 0 ; 
        int xoR2 = 0 ;
        for(int i =0 ; i< n ; i++){
            if(nums[i]&(1<<cnt)){
                xoR1 = xoR1^nums[i] ;
            }
            else 
            xoR2 = xoR2 ^ nums[i] ;
        }
        vector<int> ans ;
        ans.push_back(xoR1) ;
        ans.push_back(xoR2) ;
        sort(ans.begin(),ans.end()) ;
        return ans ;
        
        
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends