class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int sum = 0;
        int mul = 1;
        
        while (temp > 0) {
            int digit = temp % 10;
            sum += digit;
            mul *= digit;
            temp /= 10;
        }
        
        int total = sum + mul;
        return n % total == 0;
    }
};
