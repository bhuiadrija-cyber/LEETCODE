class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] == target) return mid;

            // Check if the left half is sorted
            if (nums[lo] <= nums[mid]) {
                if (nums[lo] <= target && target < nums[mid]) {
                    hi = mid - 1; // Target lies in left sorted half
                } else {
                    lo = mid + 1; // Target lies in right half
                }
            } 
            // Otherwise, the right half must be sorted
            else {
                if (nums[mid] < target && target <= nums[hi]) {
                    lo = mid + 1; // Target lies in right sorted half
                } else {
                    hi = mid - 1; // Target lies in left half
                }
            }
        }
        return -1;
    }
};