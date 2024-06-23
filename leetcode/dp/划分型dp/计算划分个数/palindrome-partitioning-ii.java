class Solution {
    public int minCut(String s) {
        int n = s.length();
        boolean[][] record = new boolean[n][n];
        for (var i = 0; i < n; ++i)
            record[i][i] = true;

        int[] dp = new int[n + 1];
        
        for (var i = 0; i < n; ++i)
        {
            dp[i + 1] = dp[i] + 1;
            for (var j = i - 1; j >= 0; --j)
            {
                if (s.charAt(i) == s.charAt(j) && (i == j + 1 || record[j + 1][i - 1]))
                {
                    record[j][i] = true;
                    dp[i + 1] = Math.min(dp[i + 1], dp[j] + 1);
                }
            }
        }
        return dp[n] - 1;
    }
}