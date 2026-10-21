class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        int n = nums.size();
        multiset<int> left, right;   // left = smaller half, right = larger half

        auto balance = [&]() {
            // left may have at most 1 more element than right
            if (left.size() > right.size() + 1) {
                auto it = prev(left.end());          // largest of left
                right.insert(*it);
                left.erase(it);
            }
            // right must never be bigger than left
            else if (right.size() > left.size()) {
                auto it = right.begin();             // smallest of right
                left.insert(*it);
                right.erase(it);
            }
        };

        for (int i = 0; i < n; i++) {
            // push nums[i] (your logic)
            int num = nums[i];
            if (left.empty() || num < *left.rbegin())
                left.insert(num);
            else
                right.insert(num);
            balance();

            // remove the element that left the window
            if (i >= k) {
                int old = nums[i - k];
                auto it = left.find(old);
                if (it != left.end()) left.erase(it);
                else right.erase(right.find(old));
                balance();
            }

            // window is full: take median (your logic)
            if (i >= k - 1) {
                if (left.size() == right.size())
                    ans.push_back(((double)*left.rbegin() + *right.begin()) / 2);
                else
                    ans.push_back(*left.rbegin());
            }
        }
        return ans;
    }
};