class Solution {
    int maxm(vector<int>& nums, int j) {
        int maxm2 = 0;
        for (int i = 0; i <= j; i++) {
            if (maxm2 < nums[i]) {
                maxm2 = nums[i];
            }
        }
        return maxm2;
    }
    int minm(vector<int>& nums, int j) {
        int minm2 = INT_MAX;
        for (int i = j; i < nums.size(); i++) {
            if (minm2 > nums[i]) {
                minm2 = nums[i];
            }
        }
        return minm2;
    }

public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> arr;
        int j = 0;
        while (j < nums.size()) {
            int maxi = maxm(nums, j);
            int mini = minm(nums, j);
            int z = maxi - mini;

            arr.push_back(z);

            j++;
        }
        if (arr.size() == 0) {
            return -1;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= k) {
                return i;
            }
            
        }
        return -1;
    }
};