class Solution {
    int bouque(vector<int>& bloomDay, int k, int day) {
        int chain = 0;
        int number = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                chain++;

                if (chain == k) {
                    number++;
                    chain = 0;
                }
            }
            else {
                chain = 0;
            }
        }

        return number;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        if ((long long)m * k > bloomDay.size())
            return -1;

        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int bouquets = bouque(bloomDay, k, mid);

            if (bouquets >= m) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};