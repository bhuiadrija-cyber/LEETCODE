class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int m=queries.size();
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i]=nums[i]+nums[i-1];
        }
        for(int i=0;i<m;i++){
            int c=0,lo=0,hi=n-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(nums[mid]<=queries[i]){
                    c=mid+1;
                    lo=mid+1;
                }
                else{
                    hi=mid-1;
                }
            }
            queries[i]=c;
        }
        return queries;
    }
};
