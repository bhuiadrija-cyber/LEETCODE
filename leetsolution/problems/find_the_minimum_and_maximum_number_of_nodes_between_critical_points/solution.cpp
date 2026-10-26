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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head==NULL || head->next==NULL || head->next->next==NULL) return {-1,-1};
        int min=INT_MAX,max=0,start=0,c=2,counter=2;
        ListNode* temp=head->next;
        ListNode* prev=head;
        while(temp->next){
            if(temp->val>prev->val && temp->val>temp->next->val || temp->val<prev->val && temp->val<temp->next->val){
                if (!start) start=c;
                else if (c-counter<min){
                    min=c-counter;
                }
                counter=c;
            }
            temp=temp->next;
            prev=prev->next;
            c++;
        }
        if(!start || start==counter) return {-1,-1};
        else max=counter-start;
        return {min,max};
    }
};