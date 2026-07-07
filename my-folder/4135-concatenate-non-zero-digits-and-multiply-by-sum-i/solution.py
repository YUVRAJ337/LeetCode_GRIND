class Solution:
    def sumAndMultiply(self, n: int) -> int:
        x=0
        totalSum=0
        for ch in str(n):
            digit=int(ch)
            if digit != 0:
                x = x*10+digit
                totalSum += digit

        return x*totalSum
        
