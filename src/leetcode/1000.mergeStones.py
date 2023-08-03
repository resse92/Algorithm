class Solution:
    def mergeStones(self, stones: List[int], k: int) -> int:
        K = k
        n = len(stones)
        if (n - 1) % (K - 1) != 0:
            return -1
        prefix_sum = [0] * (n + 1)
        for i in range(1, n + 1):
            prefix_sum[i] = prefix_sum[i - 1] + stones[i - 1]
        dp = [[[float("inf")] * (K + 1) for _ in range(n + 1)] for _ in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(i, n + 1):
                if i == j:
                    dp[i][j][1] = 0
        for length in range(2, n + 1):
            for i in range(1, n - length + 2):
                j = i + length - 1
                for m in range(2, K + 1):
                    for k in range(i, j):
                        dp[i][j][m] = min(
                            dp[i][j][m], dp[i][k][1] + dp[k + 1][j][m - 1]
                        )
                dp[i][j][1] = dp[i][j][K] + prefix_sum[j] - prefix_sum[i - 1]
        return dp[1][n][1]


# [3,2,4,1] 2
