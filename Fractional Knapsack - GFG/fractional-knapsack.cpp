//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
   static bool comp(Item a, Item b) {
    double v1 = static_cast<double>(a.value) / static_cast<double>(a.weight);
    double v2 = static_cast<double>(b.value) / static_cast<double>(b.weight);
    return v1 > v2;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, comp);
    double maxValue = 0.0;
    int weight = 0;
    for (int i = 0; i < n; i++) {
        if (weight + arr[i].weight <= W) {
            weight += arr[i].weight;
            maxValue += arr[i].value;
        } else {
            double remainingWeight = static_cast<double>(W - weight);
            double fraction = remainingWeight / static_cast<double>(arr[i].weight);
            maxValue += arr[i].value * fraction;
            break;
        }
    }

    return maxValue;
}

};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends