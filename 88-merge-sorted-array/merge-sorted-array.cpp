class Solution {
    void sorter(vector<int>& a, int m) { 
        int alp = a.size();
        int x = 0;
        int y = 1;        
        while (y < alp) { 
            if (a[x] > a[y]) {
                swap(a[x], a[y]);
                x = 0;
                y = 1; 
            } else {
                x++;
                y++;
            } 
        }
    }

public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0;
        for (int i = m; i < m + n; i++) { 
            nums1[i] = nums2[j];
            j++;
        }
        sorter(nums1, m);
        
    }
};