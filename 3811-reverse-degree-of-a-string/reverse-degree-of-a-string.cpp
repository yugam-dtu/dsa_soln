class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;

        for (int i = 0; i < s.length(); i++) {
            int value = 123 - s[i];   
            sum += (i + 1) * value;
        }

        return sum;
    }
};