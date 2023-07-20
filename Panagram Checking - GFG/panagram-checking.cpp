//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string &str) {
        if(str.size()<26){
            return 0 ;
        }
        
        map<char,int>mp ;
        for(char c : str){
           if (isalpha(c)) { // Check if the character is an alphabet
            char lowercaseChar = tolower(c);
            mp[lowercaseChar]++;
        }
        }
        
        if(mp.size() ==26){
            return true ;
        }
        return false ;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string str;
        getline(cin, str);
        Solution obj;
        if (obj.checkPangram(str) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends