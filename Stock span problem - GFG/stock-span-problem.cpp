//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        stack<pair<int, int>> st;
        vector<int> ans(n);

    ans[0] = 1;
    st.push({price[0], 0});

    for (int i = 1; i < n; i++) {
        while (!st.empty() && st.top().first <= price[i]) {
            st.pop();
        }

        ans[i] = (st.empty() ? i + 1 : i - st.top().second);
        st.push({price[i], i});
    }

    return ans;
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends