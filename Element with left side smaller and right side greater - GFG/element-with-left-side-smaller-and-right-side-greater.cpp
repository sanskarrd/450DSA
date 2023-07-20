//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends


int findElement(int a[], int n) {
    vector<int>mini(n),maxi(n);
    maxi[0]=a[0]; mini[n-1]=a[n-1];
    
    for(int i=1;i<n;i++){
        maxi[i]=max(maxi[i-1],a[i]);
    }
    for(int i=n-2;i>=0;i--){
        mini[i]=min(mini[i+1],a[i]);
    }
    
    for(int i=1;i<n-1;i++){
        
        if((mini[i]==maxi[i])&&(maxi[i]==a[i])) return a[i];
    }
    return -1;
}