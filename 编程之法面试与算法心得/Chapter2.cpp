#include <iostream>
#include <algorithm>
using namespace std;

// 寻找最小的k个数,要求时间复杂度尽可能低
// 1. 全部排序 2. 部分排序 3. 用堆代替数组 4.线性选择算法
// 这里是第四种写法
void QuickSelect(int s[], int k, int left, int right) {
	int i, j;
	int pivot;

	if (left <= right) {
		pivot = median3(s, left, right) {
			// 取三个数的中值作为主元,可以很大程度上避免最坏情况
			i = left; j = right - 1;
			while (1) {
				while (s[++i] < pivot) {};
				while (s[--j] < pivot) {};

				if (i < j) {
					swap(s[i], s[j]);
				} else {
					break;
				}

				//重置主元
				swap(s[i], s[right - 1]);

				if (k <= i) {
					QuickSelect(s, k, left, i - 1);
				} else if (k > i + 1) {
					QuickSelect(s, k, i + 1, right);
				}
			}
		}
 	} else {
		// 如果 left > right ,利用插入排序调整一下
		InsertSort(s + left, right - left + 1);
	}
}

// 寻找和为定值的两个数
// 如果数组是无序的,先排序,然后用两个指针i,j, 各自指向数组的首尾两端,逐次判断a[i]+a[j]
// 如果某一刻, a[i]+a[j] > sum, 则要想办法,让sum的值变小,则i 不动,j--
// 如果a[i]+a[j] < sum, 则让sum的值变大,i++, j不动
// 实现一下,假设数组是有序的

void TwoSum(int data[], unsigned int length, int sum) {
	// 如果数组是无需的,则事先排序
	
	int begin = 0;
	int end = length - 1;
	
	// 两头夹逼, 或称两个指针两端扫描法O(n)
	while (begin < end) {
		long curSum = data[begin] + data[end];
		
		if (curSum == sum) {
			// 符合条件
		} else {
			if (curSum < sum) {
				begin ++;
			} else {
				end --;
			}
		}
	}
}

// 寻找和为定值的多个数
// 解法1: 如果取第n个数，那么问题就转化为“取前n-1个数使得它们的和为sum-n”，对应的代码语句就是sumOfkNumber(sum - n, n - 1)；
//		  如果不取第n个数，那么问题就转化为“取前n-1个数使得他们的和为sum”，对应的代码语句为sumOfkNumber(sum, n - 1)。
list<int>list1;
void SumOfkNumber(int sum, int n)
{
	// 递归出口
	if (n <= 0 || sum <= 0)
		return;

	// 输出找到的结果
	if (sum == n)
	{
		// 反转list
		list1.reverse();
		for (list<int>::iterator iter = list1.begin(); iter != list1.end(); iter++)
			cout << *iter << " + ";
		cout << n << endl;
		list1.reverse()//此处还需反转回来
	}

	list1.push_front(n);      //典型的01背包问题
	SumOfkNumber(sum - n, n - 1);   //“放”n，前n-1个数“填满”sum-n
	list1.pop_front();
	SumOfkNumber(sum, n - 1);     //不“放”n，n-1个数“填满”sum
}

// 解法2: 这个问题属于子集合的问题(也就是背包问题),本程序采用回溯法+剪枝,其中X数组是解向量,t=∑(1,..,k-1)Wi*Xi, r=∑(k,..,n)Wi
// 且若t+Wk+W(k+1)<=M,则Xk=true，递归左儿子(X1,X2,..,X(k-1),1)；否则剪枝；
// 若t+r-Wk>=M && t+W(k+1)<=M,则置Xk=0，递归右儿子(X1,X2,..,X(k-1),0)；否则剪枝；

// 输入t， r， 尝试Wk
void SumOfkNumber(int t, int k, int r, int& M, bool& flag, bool* X)
{
	X[k] = true;   // 选第k个数
	if (t + k == M) // 若找到一个和为M，则设置解向量的标志位，输出解
	{
		flag = true;
		for (int i = 1; i <= k; ++i)
		{
			if (X[i] == 1)
			{
				printf("%d ", i);
			}
		}
		printf("\n");
	}
	else
	{   // 若第k+1个数满足条件，则递归左子树
		if (t + k + (k + 1) <= M)
		{
			SumOfkNumber(t + k, k + 1, r - k, M, flag, X);
		}
		// 若不选第k个数，选第k+1个数满足条件，则递归右子树
		if ((t + r - k >= M) && (t + (k + 1) <= M))
		{
			X[k] = false;
			SumOfkNumber(t, k + 1, r - k, M, flag, X);
		}
	}
}

void search(int& N, int& M)
{
	// 初始化解空间
	bool* X = (bool*)malloc(sizeof(bool)* (N + 1));
	memset(X, false, sizeof(bool)* (N + 1));
	int sum = (N + 1) * N * 0.5f;
	if (1 > M || sum < M) // 预先排除无解情况
	{
		printf("not found\n");
		return;
	}
	bool f = false;
	SumOfkNumber(0, 1, sum, M, f, X);
	if (!f)
	{
		printf("not found\n");
	}
	free(X);
}

// 最大连续子数组和
// 解法1: 求一个数组的最大子数组和,最直观野蛮的方法就是,三个for循环三层遍历,求出数组中每一个子数组的和,复杂度为O(n ^ 3)
int MaxSubArray(int *A, int n) {
  int maxSum = a[0]; // 全负情况,返回最大负数
  int curSum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j ++) {
      for (int k = i;k <= j; k++) {
        curSum += A[k];
      }
      if (curSum > maxSum) maxSum = curSum;

      curSum = 0; //清零,否则sum最终存放的是所有子数组的和
    }
  }
}

// 解法2: 当我们令curSum为当前最大子数组的和,maxSum为最后要返回的最大子数组的和,当我们向后面扫描的时候:
//        * 对j+1个元素有两种选择,要么放入前面找的的子数组中,要么作为新子数组的第一个元素
//        * 同时,当curSum> maxSum,则更新maxSum = curSum,否则保持原值

int MaxSubArray2(int *a,int n) {
  int curSum= 0;
  int maxSum = a[0];
  for (int i = 0; i < n; i ++) {
    curSum  = (a[i] > curSum + a[i] ? a[i] : curSum + a[i])
      maxSum = (maxSum > curSum) ? maxSum :  curSum
  }
  return maxSum
}

// 跳台阶问题
// 1.考虑最简单的问题,如果只有一级台阶,只有一种跳法,两级台阶则有两种跳法
// 讨论一般情况,把n极台阶看成是n的函数,记为f(n)
// 当n>2时,第一次跳时,就有两种选择: 一次是第一次只跳一级后面的剩下的则是f(n-1),另外一种则是第一次跳两级,后面的就是f(n-2)
long long Fibonacci(unsigned int n) {
	int result[3] = {0, 1, 2};
	if (n <= 2) {
		return result[n];
	}
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

// 2.解法1用的递归方法又许多重复计算的工作,事实上我们可以从后往前推
// 初始化时,db[0] = db[1] = 1,然后递推计算即可:db[n] = db[n -1] + db[n-2]
//1, 1, 2, 3, 5, 8, 13, 21..
int ClimbStairs(int n)
{
	int dp[3] = { 1, 1 };
	if (n < 2)
	{
		return 1;
	}
	for (int i = 2; i <= n; i++)
	{
		dp[2] = dp[0] + dp[1];
		dp[0] = dp[1];
		dp[1] = dp[2];
	}
	return dp[2];
}

// 奇偶调序
// 1.借鉴partition的实现1,维护两个指针,一个指针指向数组的第一个数字,为头指针,向右移动,一个指针指向最后一个数字,为尾指针
// 两个指针分别向中间移动,如果第一个指向偶数,第二个指向奇数,则相互交换位置 ,时间负责度为O(n)
// 判断是否是奇数
bool isOddNubmer(int data) {
	return data & 1 == 1;
}

//交换两个元素
void swap(int *x, int * y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

// 奇偶互换
void OddEvenSort(int *pData, unsigned int length) {
	if (pData == NULL || length == 0) {
		return;
	}
	
	int *pBegin = pData;
	int *pEnd = pData + length - 1;
	
	while (pBegin < pEnd) {
		// 如果pBegin 指向的是奇数,正常,向右移
		if (isOddNumber(*pBegin)) {
			pBegin ++;
		}
		else if (!*isOddNumber(*pEnd)) {
			pEnd --;
		} else {
			swap(*pBegin, *pEnd);
		}
	}
}

// 2. 快排思想

void OddEvenSort2(int data[], int lo, int hi) {
	int i = lo - 1;
	for (int j = lo; j < hi; j ++) {
		// data[j]指向奇数,交换
		if (isOddNumber(data[j])){
			i = i + 1;
			swap(&data[i], &data[j]);
		}
	}
	swap(&data[i + 1], &data[hi]);
}

// 荷兰国旗  现有n个红白蓝三种不同颜色的小球，乱序排列在一起，请通过两两交换任意两个球，使得从左至右，依次是一些红球、一些白球、一些蓝球。
// 引用自gnuhpc
//current指针所指元素为0时，与begin指针所指的元素交换，而后current++，begin++ ；
//current指针所指元素为1时，不做任何交换（即球不动），而后current++ ；
//current指针所指元素为2时，与end指针所指的元素交换，而后，current指针不动，end-- 。

void helanguoqi(int *array, int *current, int *begin, int *end) {
	while( current<=end )        
	{             
	  if( array[current] ==0 )             
		{                 
			swap(array[current],array[begin]);                  
			current++;                  
			begin++;            
		}             
		else if( array[current] == 1 )            
		{                 
			current++;            
		}   

		else //When array[current] =2   
		{               
			swap(array[current],array[end]);                
			end--;            
		}      
	}  	
}

// 矩阵相乘
// 1.暴力解法
void MulMatrix(int **matrixA, int **matrixB, int **matrixC) {
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			matrix[i][j] = 0;
			for (int k = 0; k < 2; ++k) {
				matrixC[i][j] += matrixA[i][k] * matrix[j][k];
			}
		}
	}
}

