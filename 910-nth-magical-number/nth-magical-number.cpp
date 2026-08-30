#define ll long long

class Solution {
public:
    int mod = 1e9 + 7;

    int nthMagicalNumber(int n, int a, int b) {
        ll low = 1, high = 1e17;

        ll l = std::lcm((ll)a, (ll)b);

        while (low <= high) {
            ll mid = low + (high - low) / 2;

            ll target = mid / a + mid / b - mid / l;

            if (target < n)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low % mod;
    }
};