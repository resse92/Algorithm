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
