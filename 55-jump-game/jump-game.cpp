class Solution {
public:
    int count = 2;
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        for(int i = n-2; i >= 0; i--){
            if(nums[i] == 0){
                count = 2;     int j;
                for(j = i-1; j >= 0; j--){      
                    if(nums[j] >= count) break; 
                    count++;
                }
                if(j < 0) return false;       
            }
        }
        return true;
    }
};