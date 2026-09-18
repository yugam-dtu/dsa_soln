class Solution {
    vector<int> toBinary(int num, int bits) {
        vector<int> bin(bits);
        for (int i = bits - 1; i >= 0; i--) {
            bin[i] = num % 2;
            num /= 2;
        }
        return bin;
    }

    int toDecimal(vector<int>& bin) {
        int num = 0;
        for (int b : bin) num = (num << 1) | b;
        return num;
    }

public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        int total = 1 << n;
        for (int i = 0; i < total; i++) {
            vector<int> bin = toBinary(i, n);
            vector<int> gray(n);
            gray[0] = bin[0];                    
            for (int j = 1; j < n; j++)
                gray[j] = bin[j] ^ bin[j-1];      
            ans.push_back(toDecimal(gray));
        }
        return ans;
    }
};