#include <iostream>
using namespace std;
// 4.1 有序数组的查找

// 给定一个有序的数组,查找某个数是否在数组中

int BinarySearch(int array[], int n, int value) {
  int left = 0;
  int right = n - 1;

  //如果这里是 int right = n的话,那么下面有两处地方需要修改,以保证一一对应
  // 1. 下面的循环条件则是while(left < right)
  // 2. 循环内当 array[middle] > value 的时候,right = middle

  while ( left <= right) {
    int middle = left + ((right - left) >> 1);

    if (array[middle] > value) {
      right = middle - 1;
    } else if (array[middle] < value) {
      left = middle + 1;
    } else {
      return middle;
    }

    // 可能会有读者刚开始的时候就要判断相等,但毕竟数组中不相等的情况更多
    // 如果每次循环都判断一下是否相等,浪费时间
  }
  return -1;
}

int main() {
  int array[8] = {1, 2, 3,4, 5,6,8, 7};
  int x = BinarySearch(array, 8, 1);
  cout << x << endl;

  return 0;
}
