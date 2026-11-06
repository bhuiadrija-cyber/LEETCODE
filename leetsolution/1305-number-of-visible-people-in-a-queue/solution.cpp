class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int> a(n,0);
        stack <int> st1;
        a[n-1]=0;
        st1.push(n-1);
        for(int i=n-2;i>=0;i--){
            int c=0;
            while(st1.size() && heights[st1.top()]<heights[i]) {
                st1.pop();
                c++;
            }
            if(st1.size()!=0) c++;
            a[i]=c;
            st1.push(i);
        }
        return a;
    }
};
