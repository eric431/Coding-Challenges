class Solution {
    public:
        double myPow(double x, int n) {
            if (x == 0.0 && n > 0) return 0;
            else if (x == 1.0 || n == 0) return 1;
            else if (x == -1.0) return 1.0 * (n % 2 == 0) - 1.0 * (n % 2 == 1);
    
            double result = 1.0;
            double base {};
            if (n < 0) base = 1 / x;
            else base = x;
    
            long n_long = abs(static_cast<long>(n));
            if (n_long % 2 == 1) {
                result *= base;
                --n_long;
            }
    
            for (size_t i{0}; i < n_long; i += 2) {
                result *= (base * base);
            }
    
            return result;
        }
    };