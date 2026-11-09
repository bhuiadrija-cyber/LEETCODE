class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        vector<int> suf(n);
        sort(satisfaction.begin(),satisfaction.end());
        int idx,max=0;
        suf[n-1]=satisfaction[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]+satisfaction[i];
        }
        for(int i=0;i<n;i++){
            if(suf[i]>=0){
                idx=i;
                break;
            }
        }
        int c=1;
        for(int i=idx;i<n;i++){
            max+=(satisfaction[i]*c);
            c++;
        }
        return max;
    }
};
