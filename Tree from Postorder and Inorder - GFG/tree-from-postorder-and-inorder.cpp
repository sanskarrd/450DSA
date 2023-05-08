//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
  int getPos(int element,int arr[],int start,int end){
        for(int i= start;i<= end;i++){
            if (arr[i] == element){
                return i ;
            }
        }
        return -1 ;
    }
    Node* solve(int in[] , int post[] , int inorderSt, int inorderEnd,int &indPost,int n ){
        if(indPost<0 || inorderSt>inorderEnd){
            return NULL ;
        }
        int element = post[indPost--] ;
        Node* root = new Node(element) ;
        int pos  = getPos(element,in,inorderSt,inorderEnd) ;
         root->right = solve(in, post,pos+1,inorderEnd,indPost, n) ;
        root->left = solve(in ,post,inorderSt,pos-1,indPost, n) ;
       
        
        return root ;
    }
Node *buildTree(int in[], int post[], int n) {
    
    int inorderSt= 0 ;
        int inorderEnd= n-1;
        int indPost = n-1 ;
        Node* ans = solve(in,post,inorderSt,inorderEnd,indPost, n) ;
        return ans ;

}
