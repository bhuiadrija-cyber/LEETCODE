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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* t=head;
        ListNode* l=new ListNode(0);
        ListNode* h=new ListNode(0);
        ListNode* tl=l;
        ListNode* th=h;
        int c=1;
        while(t!=NULL){
            if (c%2!=0){
                tl->next=t;
                tl=tl->next;
            }
            else{
                th->next=t;
                th=th->next;
            }
            t=t->next;
            c++;
        }
        th->next=NULL;
        tl->next=h->next;
        return l->next;
    }
};