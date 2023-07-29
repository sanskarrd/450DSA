//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool op(char c)
    {
        if(c=='*'||c=='-'||c=='+'||c=='/'||c=='^')
        return true;
    }
    // Function to convert an infix expression to a postfix expression.
    int pre(char c){
        if(c=='^')
        return 3;
        if(c=='/'||c=='*')
        return 2;
        if(c=='+'||c=='-')
        return 1;
        return 0;
    }
    string infixToPostfix(string s) {
        string ans = "" ;
        stack<char>st ;
        for(int i = 0 ; i<s.size() ; i++){
            if(isalnum(s[i])){
                ans+=s[i] ;
            }
            else if(s[i] == '('){
                st.push(s[i]) ;
            }
            else if(s[i] == ')'){
                while(!st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop() ;
                }
                  if(!st.empty() and st.top()=='(')
                st.pop();
            }
            else if (op(s[i])){
                while(!st.empty()  && pre(st.top()) >=pre(s[i]) && st.top() != '(' ){
                    ans+=st.top() ;
                    st.pop() ;
                }
                st.push(s[i]) ;
            }
        }
        
        while(!st.empty()){
        ans+=st.top();
        st.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends