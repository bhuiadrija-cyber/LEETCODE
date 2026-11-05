class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st1;
        stack<int> st2;
        int i;
        int nsi[n];
        int psi[n];
        nsi[n-1]=n;
        st1.push(n-1);
        for(i=n-1;i>=0;i--){
            while(st1.size() && heights[st1.top()]>=heights[i]) st1.pop();
            if(st1.size()==0) nsi[i]=n;
            else nsi[i]=st1.top();
            st1.push(i);
        }
        psi[0]=-1;
        st2.push(0);
        for(i=1;i<=n-1;i++){
            while(st2.size() && heights[st2.top()]>=heights[i]) st2.pop();
            if(st2.size()==0) psi[i]=-1;
            else psi[i]=st2.top();
            st2.push(i);
        }
        int m=-2;
        for(i=0;i<=n-1;i++){
            m=max(m,heights[i]*(nsi[i]-psi[i]-1));
        }
        return m;
    }
};
