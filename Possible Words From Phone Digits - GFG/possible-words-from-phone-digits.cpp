//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    
    private:
    void solve(int ind,int arr[],string&temp,unordered_map<int,string>&mp,vector<string>&ans,int n){
      if(ind>=n){
          ans.push_back(temp) ;
          return ;
      }
      
      int x = arr[ind] ;
      for(int i = 0 ; i <mp[x].size() ; i++)
      {
          temp.push_back(mp[x][i]) ;
          solve(ind+1,arr,temp,mp,ans,n);
          temp.pop_back() ;
      }
    }
    
    
    public:
    vector<string> possibleWords(int a[], int N)
    {
        vector<string>ans ;
        unordered_map<int,string>mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        
        string temp = "";
        solve(0,a,temp,mp,ans,N) ;
        return ans ;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends