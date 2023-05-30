//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
    	// Your code here
    	int odd_mask = 0x55555555 ;
    	int even_mask = 0xAAAAAAAA ;
    	int odd = (odd_mask & n);
    	int even = (even_mask & n);
    	
    	odd= odd<<1;
    	even = even>>1 ;
    	int ans  = odd|even ;
    	return ans ;
    	
    	 
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;//testcases
	while(t--)
	{
		unsigned int n;
		cin>>n;//input n
		
		Solution ob;
		//calling swapBits() method
		cout << ob.swapBits(n) << endl;
	}
	return 0;
}
// } Driver Code Ends