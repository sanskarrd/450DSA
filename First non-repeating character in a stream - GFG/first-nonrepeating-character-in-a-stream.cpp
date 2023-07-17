//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){        
		    string ans = "";                                      
		    unordered_map<char,int>mp ;
		    queue<char>q ;
		    ans+=A[0] ;
		    mp[A[0]]++ ;
		    q.push(A[0]);
		    for(int i=1 ; i<A.size() ; i++){
		        mp[A[i]]++ ;   
		        if(mp[A[i]] ==1){
		            q.push(A[i]) ;
		        }
		        
		        while(!q.empty() && mp[q.front()] > 1){
		            q.pop() ;
		        }
		        if(q.empty()){
		            ans+='#' ;
		        }
		        else{
		            ans+=q.front() ;
		        }
		    }
		    
		    return ans ;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends