class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (nums[n - 1] < nums[0]) {
            int low = 0;
            int high = n - 1;
            while (low < high) {

                int mid = (low + high) / 2;
                if (nums[mid] > nums[n - 1]) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            return nums[high];
        } else {
            return nums[0];
        }
    }
};