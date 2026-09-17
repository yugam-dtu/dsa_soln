class Solution {
    long long MOD = 1000000007;

    long long power(long long a, long long b) {
        long long ans = 1;

        while (b > 0) {
            if (b & 1)
                ans = ans * a % MOD;

            a = a * a % MOD;
            b /= 2;
        }

        return ans;
    }

    long long factorial(int n) {
        long long ans = 1;

        for (int i = 1; i <= n; i++) {
            ans = ans * i % MOD;
        }

        return ans;
    }

    long long com(int n, int r) {
        long long numerator = factorial(n);
        long long denominator = factorial(r) * factorial(n - r) % MOD;

        return numerator * power(denominator, MOD - 2) % MOD;
    }

public:
    int numberOfSets(int n, int k) {
        return com(n + k - 1, 2 * k);
    }
};