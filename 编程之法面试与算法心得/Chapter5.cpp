// 5.1 最大连续乘积子串
// 给一个浮点数序列,取最大乘积连续子串的值

// 1 暴力解法
double maxProductSubstring(double *a, int length) {
  double maxResult = a[0];
  for (int i = 0; i < length; i ++) {
    double x = 1;
    for (int j = i; j < length; j ++ ) {
      x *= a[j];
      if (x > maxResult) {
        maxResult = x;
      }
    }
  }
  return maxResult;
}

//2 动态规划
// 考虑到乘积子序列有正有负也有可能为0,可以简化成,数组中找一个子序列,使得它的乘积最大;
// 同事找一个子序列,使得他的乘积最小(负数的情况).虽然我们只要一个最大积,
// 但是由于负数的存在,我们同时找这两个乘积做起来更加方便
// 动态规划,1.先找到问题的状态 2.找到状态转移方程
double MaxProductSubstring(double *a, int length) {
  double maxEnd = a[0];
  double minEnd = a[0];
  double maxResult = a[0];
  for (int i = 1; i< length; ++i) {
    double end1 = maxEnd * a[i], end2 = minEnd * a[i];

    maxEnd = max(max(end1, end2), a[i]);
    minEnd = min(min(end1, end2), a[i]);
    maxResult = max(maxResult, maxEnd);
  }

  return maxResult;
}


// 动态规划背包问题http://www.hawstein.com/posts/dp-knapsack.html

//5.2 字符串编辑距离

//dp[i][j]表示源串source[0-i)和目标串target[0-j)的编辑距离
int EditDistance(char *pSource, char *pTarget)
{
    int srcLength = strlen(pSource);
    int targetLength = strlen(pTarget);
    int i, j;
    //边界dp[i][0] = i，dp[0][j] = j
    for (i = 1; i <= srcLength; ++i)
    {
        dp[i][0] = i;
    }
    for (j = 1; j <= targetLength; ++j)
    {
        dp[0][j] = j;
    }
    for (i = 1; i <= srcLength; ++i)
    {
        for (j = 1; j <= targetLength; ++j)
        {
            if (pSource[i - 1] == pTarget[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[srcLength][targetLength];
}
