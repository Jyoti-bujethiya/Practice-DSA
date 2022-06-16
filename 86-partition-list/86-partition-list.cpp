/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
         ListNode* less=new ListNode(0);
        ListNode* ls=less;
        ListNode* rest=new ListNode(0);
        ListNode* rs=rest;
        ListNode* temp=head,*temp1=head;
        while(temp!=NULL)
        {
            if(temp->val<x)
            {
                ls->next=temp;
                ls=ls->next;
            }
            else
            {   
                rs->next=temp;
                rs=rs->next;
            }
             temp=temp->next;
        }
        rs->next=NULL;
        ls->next=rest->next;
       
        
        return less->next;
    }
};