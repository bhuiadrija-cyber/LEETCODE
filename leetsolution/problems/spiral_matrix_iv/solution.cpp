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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> a(m,vector<int> (n,-1));
        ListNode* temp=head;
        int maxr=m-1, maxc=n-1, minr=0, minc=0;
        while (maxr>=minr && maxc>=minc){
            for (int j=minc;j<=maxc;j++){
                if (temp==NULL) return a;
                a[minr][j]=temp->val;
                temp=temp->next;  
            }
            minr++;
            if (minr>maxr) break;
            for (int j=minr;j<=maxr;j++){
                if (temp==NULL) return a;
                a[j][maxc]=temp->val;
                temp=temp->next;
            }
            maxc--;
            if (maxc<minc) break;
            for (int j=maxc;j>=minc;j--){
                if (temp==NULL) return a;
                a[maxr][j]=temp->val;
                temp=temp->next;    
            }
            maxr--;
            if (maxr<minr) break;
            for (int j=maxr;j>=minr;j--){
                if (temp==NULL) return a;
                a[j][minc]=temp->val;
                temp=temp->next;    
            }
            minc++;
            if (minc>maxc) break;
        }
        return a;
    }
};