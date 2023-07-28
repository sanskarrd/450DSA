//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        if(str1.size()!=str2.size()){
            return 0 ;
        }
        if(str1.size() == str2.size() ==1){
            if(str1==str2){
                return 1 ;
            }
        }
        int n = str1.size() ;
        string left="" ;
        string right="" ;
        
        for(int i = 2 ; i<str1.size() ; i++){
            left+=str1[i];
        }
        left+=str1[0] ;
        left+=str1[1] ;
        
        
        right+=str1[n-2];
        right+=str1[n-1] ;
        for(int i = 0 ; i<n-2; i++){
            right+=str1[i] ;
        }
      
       if(left==str2 || right==str2){
           return 1;
       }
       
       return 0 ;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends