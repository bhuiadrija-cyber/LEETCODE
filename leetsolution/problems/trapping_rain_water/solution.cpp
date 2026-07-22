class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int min[n],s=0;
        min[0]=-1;
        min[n-1]=-1;
        int max=height[0];
        for(int i=1;i<n-1;i++){
            min[i]=max;
            if (max<height[i]) max=height[i];
        }
        max=height[n-1];
        for(int i=n-2;i>0;i--){
            if (min[i]>max) min[i]=max;
            if (max<height[i]) max=height[i];
        }
        for(int i=1;i<n-1;i++){
            if (min[i]>height[i]) s+=(min[i]-height[i]);
        }
        return s;
    }
};