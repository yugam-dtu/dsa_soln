class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixsum(n);

        prefixsum[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefixsum[i] = prefixsum[i-1] + nums[i];
        }

        int count = 0;
        for(int i = 0; i < n; i++){
            if(prefixsum[i] == k) count++;      
            for(int j = i-1; j >= 0; j--){     
                if(prefixsum[i] - prefixsum[j] == k) count++;
            }
        }
        return count;
    }
};