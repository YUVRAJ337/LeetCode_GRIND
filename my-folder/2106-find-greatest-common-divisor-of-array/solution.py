class Solution(object):
    def findGCD(self, nums):
        
        min_val = min(nums)
        max_val = max(nums)
        
        # Euclidean algorithm to find GCD
        while max_val % min_val != 0:
            remainder = max_val % min_val
            max_val = min_val
            min_val = remainder
            
        return min_val
