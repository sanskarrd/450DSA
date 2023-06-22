//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
         int inDeg[N] = {0} ;
         vector<int>adj[N];
         
         //creating  a adjacency list ;
         for(auto it:prerequisites){
             adj[it.first].push_back(it.second) ;
         }
         //finding indegree
       for(int i = 0 ;i <N ; i++)
       for(auto it: adj[i]){
           inDeg[it] ++ ;
       }
       //pushing it in queue if indegree = 0
         queue<int>q ;
         for(int i = 0 ; i<N; i++){
             if(inDeg[i] == 0 ){
                 q.push(i) ;
             }
         }
         
         vector<int> topo ;
         while(!q.empty()){
             
             int node = q.front() ;
             q.pop() ;
             topo.push_back(node) ;
             
             for(auto it: adj[node]){
                 inDeg[it] -- ;
                 if(inDeg[it] == 0){
                     q.push(it) ;
                 }
             }
         }
         
         if(topo.size()<N){
             return false ;
         }
         else if(topo.size() == N){
            return true ;
         }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends