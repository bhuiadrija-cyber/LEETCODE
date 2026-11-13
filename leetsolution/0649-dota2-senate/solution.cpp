class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=senate.length();
        queue<int> q;
        queue<int> r;
        queue<int> d;
        string won;
        for(int i=0;i<n;i++) {
            q.push(i);
            if(senate[i]=='R') r.push(i);
            else d.push(i);
        }
        while(q.size()>1){
            if(senate[q.front()]=='R') {
                if (d.size()==0) {
                    return "Radiant";
                }
                int x=d.front();
                senate[x]='X';
                d.pop();
                x=r.front();
                r.pop();
                r.push(x);
                x=q.front();
                q.pop();
                q.push(x);
            }
            else if(senate[q.front()]=='D') {
                if (r.size()==0) {
                    return "Dire";
                }
                int x=r.front();
                r.pop();
                senate[x]='X';
                x=d.front();
                d.pop();
                d.push(x);
                x=q.front();
                q.pop();
                q.push(x);
            }
            else if(senate[q.front()]=='X') {
                q.pop();
            }
        }
        if(q.size()==1) {
            if(senate[q.front()]=='R') won="Radiant";
            else won="Dire";
        }
        return won;
    }
};
