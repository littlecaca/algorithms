from typing import List
from functools import cache


class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        n = len(nums)
        nums = [1] + nums + [1]

        @cache
        def recur(start: int, end: int) -> int:
            if start + 1 == end:
                return 0
            if start + 2 == end:
                return nums[start] * nums[start + 1] * nums[end]
            return max(
                recur(start, x) + recur(x, end) + nums[start] * nums[x] * nums[end]
                for x in range(start + 1, end)
            )

        return recur(0, n + 1)
