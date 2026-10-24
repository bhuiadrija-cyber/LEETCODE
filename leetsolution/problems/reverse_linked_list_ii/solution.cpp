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
    ListNode* reverseList(ListNode* head) {
        if (head==NULL || head->next==NULL) return head;
        ListNode* current=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(current!=NULL){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left==right) return head;
        ListNode* a;
        ListNode* b;
        ListNode* c;
        ListNode* d;
        ListNode* temp=head;
        int n=1;
        while(temp!=NULL){
            if (n==left-1) a=temp;
            else if (n==left) b=temp;
            else if (n==right) c=temp;
            else if (n==right+1) {
                d=temp;
                break;
            }
            n++;
            temp=temp->next;
        }
        if (a) a->next=NULL;
        c->next=NULL;
        c=reverseList(b);
        if (a) a->next=c;
        b->next=d;
        if (a) return head;
        return c;
    }
};