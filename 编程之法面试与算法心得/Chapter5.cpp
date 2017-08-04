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

//5.3 格子取数问题
// 有n*n个格子.每个格子都是非负数,从左上角到最右下角,只能向下或者向右,一个走两次,把所有经过的格子的数加起来,求最大值SUM,且如果两次经过同一个格子,只计数一次

const int N = 202;
const int inf = 1000000000;  //无穷大
int dp[N * 2][N][N];
bool IsValid(int step, int x1, int x2, int n) //判断状态是否合法
{
    int y1 = step - x1, y2 = step - x2;
    return ((x1 >= 0) && (x1 < n) && (x2 >= 0) && (x2 < n) && (y1 >= 0) && (y1 < n) && (y2 >= 0) && (y2 < n));
}

int GetValue(int step, int x1, int x2, int n)  //处理越界 不存在的位置 给负无穷的值
{
    return IsValid(step, x1, x2, n) ? dp[step][x1][x2] : (-inf);
}

//状态表示dp[step][i][j] 并且i <= j, 第step步  两个人分别在第i行和第j行的最大得分 时间复杂度O(n^3) 空间复杂度O(n^3)
int MinPathSum(int a[N][N], int n)
{
    int P = n * 2 - 2; //最终的步数
    int i, j, step;

    //不能到达的位置 设置为负无穷大
    for (i = 0; i < n; ++i)
    {
        for (j = i; j < n; ++j)
        {
            dp[0][i][j] = -inf;
        }
    }
    dp[0][0][0] = a[0][0];

    for (step = 1; step <= P; ++step)
    {
        for (i = 0; i < n; ++i)
        {
            for (j = i; j < n; ++j)
            {
                dp[step][i][j] = -inf;
                if (!IsValid(step, i, j, n))   //非法位置
                {
                    continue;
                }
                //对于合法的位置进行dp
                if (i != j)
                {
                    dp[step][i][j] = max(dp[step][i][j], GetValue(step - 1, i - 1, j - 1, n));
                    dp[step][i][j] = max(dp[step][i][j], GetValue(step - 1, i - 1, j, n));
                    dp[step][i][j] = max(dp[step][i][j], GetValue(step - 1, i, j - 1, n));
                    dp[step][i][j] = max(dp[step][i][j], GetValue(step - 1, i, j, n));
                    dp[step][i][j] += a[i][step - i] + a[j][step - j];  //不在同一个格子，加两个数
                }
                else
                {
                    dp[step][i][j] = max(dp[step][i][j], GetValue(step - 1, i - 1, j - 1, n));
                    dp[step][i][j] = max(dp[step][i][j], GetValue(step - 1, i - 1, j,  n));
                    dp[step][i][j] = max(dp[step][i][j], GetValue(step - 1, i, j,  n));
                    dp[step][i][j] += a[i][step - i]; // 在同一个格子里，只能加一次
                }
            }
        }
    }
    return dp[P][n - 1][n - 1];
}
