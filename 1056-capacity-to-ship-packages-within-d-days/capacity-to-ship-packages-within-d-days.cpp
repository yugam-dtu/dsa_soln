class Solution {
   int helper(vector<int>& weights, int mid) {
    int newday = 1;
    int sum = 0;

    for (int i = 0; i < weights.size(); i++) {

        if (weights[i] > mid)
            return INT_MAX;

        if (sum + weights[i] > mid) {
            newday++;
            sum = 0;
        }

        sum += weights[i];
    }

    return newday;
}
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0;
        int n = weights.size();
        int high = 0;
        for (int x : weights) {
            high += x;
        }
        while (low <= high) {

            int mid = low + (high - low) / 2;
            int newday = helper(weights, mid);
             if (newday <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};