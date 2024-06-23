class Solution:
    def temperatureTrend(self, temperatureA: List[int], temperatureB: List[int]) -> int:
        cur = 0
        ans = 0
        for i in range(1, len(temperatureA)):
            s1 = temperatureA[i] - temperatureA[i - 1]
            s2 = temperatureB[i] - temperatureB[i - 1]
            if s1 == 0 and s2 == 0 or s1 * s2 > 0:
                cur += 1
                ans = max(ans, cur)
            else:
                cur = 1
        return ans
        