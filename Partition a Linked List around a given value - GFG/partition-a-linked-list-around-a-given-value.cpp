// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    // code here
     Node *h1 = 0 , *h2 = 0 , *h3 = 0 , *t1 = 0 , *t2 = 0 , *t3 = 0 ;
    Node *t = head ;
    
    while(t){
        Node *tt = t ;
        t = t->next ;
        tt->next = 0 ;
        if(tt->data < x){
            if(!h1){
                h1 = tt ;
                t1 = tt ;
            }else{
                t1->next = tt ;
                t1 = tt ;
            }
        }else if(tt->data == x){
            if(!h2){
                h2 = tt ;
                t2 = tt ;
            }else{
                t2->next = tt ;
                t2 = tt ;
            }
        }else{
            if(!h3){
                h3 = tt ;
                t3 = tt ;
            }else{
                t3->next = tt ;
                t3 = tt ;
            }
        }
    }
    
    Node *nh = 0 , *nt = 0 ;
    if(h1){
        nh = h1 ;
        nt = t1 ;
        if(h2){
            nt->next = h2 ;
            nt = t2 ;
        }
        if(h3){
            nt->next = h3 ;
            nt = t3 ;
        }
    }else if(h2){
        nh = h2 ;
        nt = t2 ;
        if(h3){
            nt->next = h3 ;
            nt = t3 ;
        }
    }else{
        nh = h3 ;
    }
    return nh ;
}