//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
	    set<int>ans ;
	    for(int i = 2 ; i<=N ; i++){
	        while(N%i==0){
	            ans.insert(i);
	            N = N/i;
	        }
	    }
	    vector<int>res;
	    for(auto i : ans){
	        res.push_back(i) ;
	    }
	    return res ;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends