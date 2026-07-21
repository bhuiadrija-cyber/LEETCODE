class Solution {
public:
    void swap(int &x, int &y){
    int temp = x;
    x=y;
    y=temp;
    return;
    }
    void nextPermutation(vector<int>& nums) {
        int pidx=-1;
        int n=nums.size();
        for(int i=n-1;i>0;i--){
            if (nums[i]>nums[i-1]) {
                pidx=i-1;
                break;
            }
        }
        if (pidx==-1){
            reverse (nums.begin(), nums.end());
            return;
        }
        for(int i=n-1;i>0;i--){
            if (nums[i]>nums[pidx]) {
                swap(nums[i],nums[pidx]);
                break;
            }
        }
        reverse(nums.begin()+pidx+1,nums.end());
        return;
    }
};