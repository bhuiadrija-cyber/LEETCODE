class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n==1) return 0;
        int prev;
        if(k%2==0){
            prev=kthGrammar(n-1, k/2);
            if (prev==0) prev= 1;
            else prev= 0;
        }
        else if(k%2!=0){
            prev=kthGrammar(n-1, k/2+1);
        }
        return prev;
    }
};
