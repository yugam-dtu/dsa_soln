class Solution {
    void sorter(vector<int>& a, int m) {
        int alp = a.size();
        if (m >= alp) return;                  // no second half, nothing to merge
        for (int x = 0; x < m; x++) {
            if (a[x] > a[m]) {
                swap(a[x], a[m]);
                int y = m;
                while (y + 1 < alp && a[y] > a[y + 1]) {
                    swap(a[y], a[y + 1]);
                    y++;
                }
            }
        }
    }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0;
        for (int i = m; i < m + n; i++) nums1[i] = nums2[j++];
        sorter(nums1, m);
    }
};