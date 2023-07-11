//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int nums[], int n , int target )
{
    int low = 0, high = n-1;
        int start = -1, end = -1;

        // Searching the start index of target
        while(low<=high)
        {
            int mid = low + (high-low)/2;

            if(nums[mid] < target)
            { 
                low = mid+1; 
            }

            else if(nums[mid] > target)
            { 
                high = mid-1; 
            }

            else
            {   // nums[mid] == target
                start = mid;
                high = mid-1;
            }
        }
        
        // Searching the end index of target
        if(start!=-1)
        {
            low = 0, high = n-1;
            while(low<=high)
            {
                int mid = low + (high-low)/2;
                if(nums[mid] < target)
                { 
                    low = mid+1; 
                }

                else if(nums[mid] > target)
                { 
                    high = mid-1; 
                }

                else
                {   // nums[mid] == target
                    end = mid;
                    low = mid+1;
                }
            }
        }

        return {start, end};
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends