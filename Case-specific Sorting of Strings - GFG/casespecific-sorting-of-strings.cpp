//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string lower ="" ;
        string upper = "" ;
        
        for(int i = 0 ; i< n ; i++){
            if(islower(str[i])){
                lower+=str[i] ;
            }
            else {
                upper += str[i] ;
            }
        }
        
        sort(upper.begin(),upper.end()) ;
        sort(lower.begin(),lower.end()) ;
        int a=0,b = 0 ;
        string ans = "";
        for(int i = 0 ; i< n ; i++){
            if(islower(str[i]) && a<lower.size()){
                ans+=lower[a] ;
                a++ ;
            }
            else{
                ans+=upper[b] ;
                b++ ;
            }
        }
        return ans ;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends