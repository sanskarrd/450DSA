//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	string removeDups(string S) 
	{
	    // Your code goes here
	         map<char,int>m;
        
        for(int i=0;i<S.length();i++){
            m[S[i]]++;
        }
        string str="";
        
        for(int i=0;i<S.length();i++){
            char ch=S[i];
            if(m.find(ch)!=m.end() ){
                str=str+ch;
                m.erase(ch);
            }
        }
        
        return str;
	}
};

//{ Driver Code Starts.


int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   		
   		Solution ob;
   		cout << ob.removeDups(s) << "\n";
   		
   	}

    return 0;
}
// } Driver Code Ends