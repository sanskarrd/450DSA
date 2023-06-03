//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
void solve(int low, int high, vector<int>& nums, vector<int>& ans)
    {
        if(low > high)
        {
            return;
        }
        int mid = (low+high) >> 1;
        ans.push_back(nums[mid]);
        solve(low, mid-1, nums, ans); // first left
        solve(mid+1, high, nums, ans); // then right
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        vector<int> ans;
        solve(0, nums.size()-1, nums, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends