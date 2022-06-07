// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; 

void preOrder(TNode* node)  
{  
    if (node == NULL)  
        return;  
    cout<<node->data<<" ";  
    preOrder(node->left);  
    preOrder(node->right);  
} 


 // } Driver Code Ends
//User function Template for C++


//User function Template for C++

/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */
class Solution{
  public:
   int count(LNode* head) {
       if (head == NULL)
           return 0;
       int ans = 0;
       while (head != NULL) {
           ans++;
           head = head -> next;
       }
       return ans;
   }
   TNode* sortedListToBST(LNode *head) {
       //code here
       if (head == NULL)
           return NULL;
           
       if (head -> next == NULL) {
           TNode* root = new TNode(head -> data);
           return root;
       }
       
       int length = count(head);
       length = length/2;
       LNode* ptr = head;
       length--;
       while (length--) ptr = ptr -> next;
       
       LNode* mid = ptr -> next;
       ptr -> next = NULL;
       LNode* rNode = mid -> next;
       mid -> next = NULL;
       TNode* root = new TNode(mid -> data);
       TNode* left = sortedListToBST(head);
       TNode* right = sortedListToBST(rNode);
       root -> left = left;
       root -> right = right;
       return root;
       
       
       
   }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int data;
        cin>>data;
        LNode *head = new LNode(data);
        LNode *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout<<"\n";
        
    }
    return 0;
}
  // } Driver Code Ends