//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	void solve(int i,int j,string s,string t,string ans,int length,vector<string>&res,map<string,int>&mp){
	     if(length==0){
           reverse(ans.begin(),ans.end());
           if(mp.find(ans)==mp.end()){
	           res.push_back(ans);
               mp[ans]++;
           }
           return;
        }
        
	     if(i==0 || j==0){
            return;
        }
        
        
        for(int row=i;row>0;row--){
	        for(int col=j;col>0;col--){
                if(s[row-1]==t[col-1]){
                    ans+=s[row-1];
                    solve(row-1,col-1,s,t,ans,length-1,res,mp);
                    ans.pop_back();
                }
            }   
        }
        
	}
		vector<string> all_longest_common_subsequences(string str1, string str2)
		{
		int n=str1.length();
	    int m=str2.length();
	    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        vector<string>res ;
        map<string,int>mp ;
        int len  = dp[n][m] ;
        solve(n,m,str1,str2,"",len,res,mp);
        sort(res.begin(),res.end());
        return res;
    
	}
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends