class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
         int n=nums.size();
        vector<int> prefix_sum(n);
        vector<int> suffix_sum(n);
        
       
        prefix_sum[0]=nums[0];
        suffix_sum[n-1]=nums[n-1];

        for(int i=1;i<n;i++){
            prefix_sum[i]=max(prefix_sum[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            suffix_sum[i]=min(suffix_sum[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
            if((prefix_sum[i]-suffix_sum[i])<=k)
            {return i;}
        }
        return -1;

      



    }
};