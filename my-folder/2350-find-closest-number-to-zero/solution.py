class Solution(object):
    def findClosestNumber(self , nums: list[int]) -> int:
        closest = nums[0]
        for x in nums:
            if abs(x) < abs(closest):
                closest=x

            elif abs(x) == abs(closest):
                if x > closest:
                    closest = x
        return closest


              
 
        
