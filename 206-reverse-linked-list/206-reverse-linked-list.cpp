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
    ListNode* reverseList(ListNode* h1) {
        ListNode* h2=NULL;
        ListNode*temp=NULL;
        while(h1!=NULL){
            temp=h1;
            h1=h1->next;
            temp->next=h2;
            h2=temp;
        }
        return h2;
    }
};