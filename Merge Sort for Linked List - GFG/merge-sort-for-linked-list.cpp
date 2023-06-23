//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
    private:
 Node* findMid(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

    
  Node* merge(Node* head1, Node* head2) {
    Node* dummy = new Node(0);
    Node* curr = dummy;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            curr->next = head1;
            head1 = head1->next;
        } else {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }

    if (head1 != NULL) {
        curr->next = head1;
    }
    if (head2 != NULL) {
        curr->next = head2;
    }

    Node* newHead = dummy->next;
    delete dummy;
    return newHead;
}

  public:
    //Function to sort the given linked list using Merge Sort.
   Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* mid = findMid(head);
    Node* midNext = mid->next;
    mid->next = NULL;  // Splitting the list into two halves
    Node* temp1 = mergeSort(head);
    Node* temp2 = mergeSort(midNext);
    return merge(temp1, temp2);
}

};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends