class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
    uint64_t x[2] = {0, 0};

    for (auto& n : nums) {
        if (n % k == 0) {
            int i = n / k - 1;
            // Store the mult in the correct 64-bit block.
            if (i < 64)
                x[0] |= 1ULL << i;
            else
                x[1] |= 1ULL << (i - 64);
        }
    }

    int mult;
    if (x[0] != -1ULL) {
        // The first missing mult is in x[0].
        mult = bit_width(++x[0] & -x[0]);
    } else {
        // The first 64 positions are present,
        // so the missing mult is in x[1].
        mult = 64 + bit_width(++x[1] & -x[1]);
    }

    return mult * k;
 }
};
