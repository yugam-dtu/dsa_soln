class Solution { 
    int sum = 0; 

    int divsum(vector<int>& nums, int mid) { 
        sum = 0;

        for(int i = 0; i < nums.size(); i++) { 
            sum = (nums[i] + mid - 1) / mid + sum; 
        } 

        return sum; 
    } 

public: 
    int smallestDivisor(vector<int>& nums, int threshold) { 
        int low = 1, high = 1e6; 
        int mid;

        while(low <= high) { 
            mid = (low + high) / 2; 

            if(divsum(nums, mid) > threshold) { 
                low = mid + 1; 
            } 
            else { 
                high = mid - 1; 
            } 
        } 

        return low; 
    } 
};