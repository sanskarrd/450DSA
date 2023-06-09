//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends



int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
    priority_queue<int,vector<int>,greater<int>> pq;
 
 for(int i=0;i<n;i++){
     for(int j=0;j<n;j++){
         pq.push(mat[i][j]);
     }
 }
 
 int p=0;
 int top=0;
 while(!pq.empty() && p<k){
     top=pq.top();
     pq.pop();
     p++;
 }
 return top;
}
