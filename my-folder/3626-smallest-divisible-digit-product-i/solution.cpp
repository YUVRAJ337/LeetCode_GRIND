class Solution {
public:
    // Helper function to calculate the product of digits
    int getDigitProduct(int num) {
        int prod = 1;
        while (num > 0) {
            prod *= (num % 10);
            num /= 10;
        }
        return prod;
    }

    int smallestNumber(int n, int t) {
        while (true) {
            if (getDigitProduct(n) % t == 0) {
                return n;
            }
            n++;
        }
    }
};
