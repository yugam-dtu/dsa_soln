#include <vector>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        std::vector<int> arr(n1 + n2);
        int i = 0, j = 0, k = 0;

        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) {
                arr[k] = nums1[i];
                i++;
            } else {
                arr[k] = nums2[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of nums1, if any
        while (i < n1) {
            arr[k] = nums1[i];
            i++;
            k++;
        }

        // Copy the remaining elements of nums2, if any
        while (j < n2) {
            arr[k] = nums2[j];
            j++;
            k++;
        }

        int totalSize = n1 + n2;
        if (totalSize % 2 == 1) {
            return arr[totalSize / 2];
        } else {
            return (arr[totalSize / 2 - 1] + arr[totalSize / 2]) / 2.0;
        }
    }
};