/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        Node* dummy=new Node(-100);
        Node* td=dummy;
        while(temp){
            td->next=new Node(temp->val);
            temp=temp->next;
            td=td->next;
        }
        dummy=dummy->next;
        Node* another=new Node(-1000);
        td=another;
        Node* b=head;
        Node* a=dummy;
        while(b){
            td->next=b;
            b=b->next;
            td=td->next;
            td->next=a;
            a=a->next;
            td=td->next;
        }
        another=another->next;
        td=another;
        while(td){
            temp=td->next;
            if (td->random){
                temp->random=td->random->next;
            }
            td=td->next->next;
        }
        head=new Node(-1);
        dummy=new Node(-9);
        Node* t1=head;
        Node* t2=dummy;
        temp=another;
        while(temp){
            t1->next=temp;
            temp=temp->next;
            t1=t1->next;
            t2->next=temp;
            temp=temp->next;
            t2=t2->next;
        }
        t1->next=NULL;
        t2->next=NULL;
        return dummy->next;
    }
};