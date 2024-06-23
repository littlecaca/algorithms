from typing import List

class Solution:
    def countSpecialSubsequences(self, nums: List[int]) -> int:
        dp = [0, 0]
        mod = int(1e9 + 7)
        ans = 0
        for n in nums:
            if n == 0:
                dp[0] = (dp[0] * 2 + 1) % mod
            elif n == 1:
                dp[1] = (dp[0] + dp[1] * 2) % mod
            elif n == 2:
                ans = (ans * 2 + dp[1]) % mod

        return ans
                    
                
            