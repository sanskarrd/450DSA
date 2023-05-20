//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int n, int k, vector<int> &hand) {
        // code here
         if(n%k){
            return false;
        }
        map<int,int> ump;
        for(auto x:hand){
            ump[x]++;
        }
        k--;
        for(auto x:ump){
            int a = x.first;
            while(ump[a]>0){
              int val=a;      
              for(int i=0;i<k;i++){
                  val += 1;
                  if(ump[val]>0){
                     ump[val]--;
                  }
                  else{
                     return false;
                  }
              }
              ump[a]--;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends