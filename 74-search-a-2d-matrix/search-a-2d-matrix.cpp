class Solution {
    // returns the index of the last row whose first element <= target (-1 if none)
    int columnhelper(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int low = 0, high = m - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid][0] <= target) {
                ans = mid;          // candidate row, try to go lower
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    // binary search for target inside the chosen row
    bool rowhelper(vector<vector<int>>& matrix, int target, int row) {
        if (row == -1) return false;
        int low = 0, high = matrix[row].size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = columnhelper(matrix, target);
        return rowhelper(matrix, target, row);
    }
};