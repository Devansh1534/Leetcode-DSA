class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        auto lcm = [](long long x, long long y) {
            return x / __gcd(x, y) * y;
        };
        
        long long left = 1, right = 2e9, result = 0;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long count = mid / a + mid / b + mid / c 
                         - mid / lcm(a, b) 
                         - mid / lcm(b, c) 
                         - mid / lcm(a, c) 
                         + mid / lcm(lcm(a, b), c);
                         
            if (count >= n) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return (int)result;
    }
};
