class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int k=0;
        vector<int>a(m*n);
        int maxr=m-1, maxc=n-1, minr=0, minc=0;
        while (maxr>=minr && maxc>=minc){
            for (int j=minc;j<=maxc;j++){
                a[k]=matrix[minr][j];
                k++;    
            }
            minr++;
            if (minr>maxr) break;
            for (int j=minr;j<=maxr;j++){
                a[k]=matrix[j][maxc];
                k++;
            }
            maxc--;
            if (maxc<minc) break;
            for (int j=maxc;j>=minc;j--){
                a[k]=matrix[maxr][j];
                k++;    
            }
            maxr--;
            if (maxr<minr) break;
            for (int j=maxr;j>=minr;j--){
                a[k]=matrix[j][minc];
                k++;    
            }
            minc++;
            if (minc>maxc) break;
        }
        return a;
    }
};