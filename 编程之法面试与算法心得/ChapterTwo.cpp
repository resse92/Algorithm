#include <iostream>

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

int main(int argc, char *argv[]) {
	int s[] = [1, 2, 3, 4, 5, 6];
	QuickSelect(s, 2, 0, 5)
}
