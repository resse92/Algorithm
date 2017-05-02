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

