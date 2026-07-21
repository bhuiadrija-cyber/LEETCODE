class Solution {
public:
    void swap(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
        return;
    }
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int m=0,l=0,h=n-1;
        while (m<=h){
            if(nums[m]==2){
                swap(nums[m],nums[h]);
                h--;
            }
            else if(nums[m]==0){
                swap(nums[m],nums[l]);
                l++;
                m++;
            }
            else m++;
        }
    }
};