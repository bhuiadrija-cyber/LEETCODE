class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i,j;
        int c=0;
        int max=nums[0];
        for(i=1;i<n;i++){
            if (nums[i]==max) c++;
            else{
                max=nums[i];
                c=0;
            }
            if (c==n/2) break;
        }
        return max;
    }
};