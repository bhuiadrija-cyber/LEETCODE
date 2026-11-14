class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        if(n==1) return deck;
        sort(deck.begin(),deck.end());
        if(n==2) return deck;
        queue<int> q;
        vector<int> ans(n);
        for(int i=0;i<n;i++) q.push(i);
        int i=0;
        while(q.size()>1){
            int idx=q.front();
            q.pop();
            q.push(q.front());
            q.pop();
            ans[idx]=deck[i];
            i++;
        }
        if(q.size()==1) ans[q.front()]=deck[n-1];
        return ans;
    }
};
