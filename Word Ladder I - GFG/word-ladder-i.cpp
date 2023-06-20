//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<pair<string,int>>q ;
        
        unordered_set<string>set(wordList.begin(),wordList.end()) ;
        
        q.push({startWord,1}) ;
        while(!q.empty()){
            string word = q.front().first ;
            int ans  = q.front().second ;
            q.pop() ;
            
            if(word== targetWord){
                return ans ;
            }
            
            
            for(int i = 0 ; i<word.size() ; i++){
                char chOfStart = word[i] ;
                for(char ch ='a' ; ch <='z' ; ch++){
                    word[i]= ch ;
                    if(set.find(word) !=set.end()){
                        set.erase(word) ;
                        q.push({word,ans+1}) ;
                    }
                    
                }
                word[i]= chOfStart ;
            }
        }
        return 0 ;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends