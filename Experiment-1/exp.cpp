#define ll long long
#define Mod 1000000007
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        if (a > b)
            swap(a, b);
        ll s = a, e = 1LL * n * a, mid,l=lcm(a,b);
        while (s < e) {
            mid = s + (e - s) / 2;
            int cnt = mid / a + mid / b - mid / l;
            if (cnt < n)
                s = mid + 1;
            else
                e = mid;
        }
        return s % Mod;
        ;
    }
};
