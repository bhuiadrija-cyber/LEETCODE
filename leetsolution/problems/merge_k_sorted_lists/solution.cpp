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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=new ListNode;
        ListNode* temp=head;
        while(list1!=NULL && list2!=NULL){
            if (list1->val<=list2->val){
                temp->next=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
        if (list2==NULL){
            temp->next=list1;
        }
        else{
            temp->next=list2;
        }
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        while(lists.size()>1){
            ListNode* a=lists[0];
            lists.erase(lists.begin());
            ListNode* b=lists[0];
            lists.erase(lists.begin());
            ListNode* c=mergeTwoLists(a, b);
            lists.push_back(c);
        }
        return lists[0];
    }
};