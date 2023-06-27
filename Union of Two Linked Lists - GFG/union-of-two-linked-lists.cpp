//{ Driver Code Starts
#include<bits/stdc++.h>
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


// } Driver Code Ends
/*
// structure of the node is as follows

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
class Solution
{
      // struct Node* temp = new Node(-1) ;
        // struct Node* curr = temp ;
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        struct Node* temp1 = head1 ;
        struct Node* temp2 = head2 ;
        
        set<int>st ;
        while(temp1!=NULL){
            if(st.find(temp1->data) == st.end())
            st.insert(temp1->data) ;
            temp1 = temp1->next ;
        }
        while(temp2!=NULL){
            if(st.find(temp2->data) == st.end())
            st.insert(temp2->data) ;
            temp2 = temp2->next ;
        }
        
        struct Node* temp =new Node(0) ;
        struct Node* curr = temp;
        for(auto itr:st){
            curr->next = new Node(itr) ;
            curr = curr->next ;
        }
        
        return temp->next ;
    }
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends