//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	     sort(arr,arr+n);
        int i,j,count=0,left,right; //left & right pointers decleared
      
        for(i=n-1;i>=0;i--){ //reverse loop
            left=0; //left pointer start from zero.
            right=i-1; //right-pointer start from (n-2)th element.
           
            while(left<right){
              if(arr[left]+arr[right]==arr[i])
                 count++, left++, right--;
                 else if(arr[left]+arr[right]>arr[i])
                 right--;
                 else 
                 left++;}
        }
      
        
        return count;
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
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}
// } Driver Code Ends