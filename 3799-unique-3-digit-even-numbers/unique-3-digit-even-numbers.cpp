class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> se;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {

                  
                    if (digits[k] % 2 == 0) {
                        if (digits[i] != 0)
                            se.insert(digits[i] * 100 + digits[j] * 10 + digits[k]);

                        if (digits[j] != 0)
                            se.insert(digits[j] * 100 + digits[i] * 10 + digits[k]);
                    }

                 
                    if (digits[j] % 2 == 0) {
                        if (digits[i] != 0)
                            se.insert(digits[i] * 100 + digits[k] * 10 + digits[j]);

                        if (digits[k] != 0)
                            se.insert(digits[k] * 100 + digits[i] * 10 + digits[j]);
                    }

                   
                    if (digits[i] % 2 == 0) {
                        if (digits[j] != 0)
                            se.insert(digits[j] * 100 + digits[k] * 10 + digits[i]);

                        if (digits[k] != 0)
                            se.insert(digits[k] * 100 + digits[j] * 10 + digits[i]);
                    }
                }
            }
        }

        return se.size();
    }
};