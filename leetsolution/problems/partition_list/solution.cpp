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
        ListNode* t=head;
        ListNode* l=new ListNode(0);
        ListNode* h=new ListNode(0);
        ListNode* tl=l;
        ListNode* th=h;
        while(t!=NULL){
            if (t->val<x){
                tl->next=t;
                tl=tl->next;
            }
            else{
                th->next=t;
                th=th->next;
            }
            t=t->next;
        }
        th->next=NULL;
        tl->next=h->next;
        return l->next;
    }
};