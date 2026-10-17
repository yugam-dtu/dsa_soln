class Solution {
    int digsum(int n) {
        int s = 0;
        while (n > 0) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<array<int,3>> v(n);
        for (int i = 0; i < n; i++)
            v[i] = {digsum(nums[i]), nums[i], i};

        sort(v.begin(), v.end());   // by digit sum, then value

        vector<bool> vis(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] || v[i][2] == i) continue;
            int len = 0, j = i;
            while (!vis[j]) {
                vis[j] = true;
                j = v[j][2];
                len++;
            }
            swaps += len - 1;
        }
        return swaps;
    }
};