//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        if (head == nullptr || head->next == nullptr) {
        return head;
    }
      Node *evenhead = NULL ;
      Node *eventail = NULL;
      Node *oddtail = NULL;
      Node *oddhead = NULL;
      
      while(head!=NULL)
      {
         if(head->data %2==0) 
         {
             if(evenhead ==NULL)
             {
                 evenhead = head ;
                 eventail = head ;
             }
             else{
                 eventail->next = head ;
                 eventail = eventail->next ;
             }
         }
         else{
             if(oddhead==NULL)
             {
                 oddhead= head;
                 oddtail =head;
             }
             else{
                 oddtail->next = head ;
                 oddtail =oddtail->next ;
             }
         }
          
          head = head->next ;
      }
      if(evenhead==NULL){
          return oddhead ;
      }
      else if(oddhead ==NULL)
      {
          return evenhead ;
      }
      eventail->next = oddhead ;
      oddtail->next = NULL ;
      
      return evenhead ;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends