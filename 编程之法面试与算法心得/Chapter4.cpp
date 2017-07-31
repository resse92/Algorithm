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

// 4.2 行列递增矩阵的查找
// 在一个m行n列的二维数组中,每一行每一列都按照从左到右递增的顺序排序,每一列从上到下的顺序排序.判断数组中是否含有某个整数
#define ROW 4
#define COL 4
bool YoungMatrix(int array[][COL], int searchKey) {
  int i = 0, j = COL - 1;
  int var = array[i][j];
  while (true) {
    if (var == searchKey) {
      return true;
    } else if (var < searchKey && i < ROW - 1) {
      var = array[++i][j];
    } else if (var > searchKey && j > 0) {
      var = array[i][--j];
    } else {
      return false;
    }
  }
}

// 4.3 出现次数超过一半的数字
// 数组中有一个数字出现的次数超过了数组长度的一半,找出这个数字
//a代表数组，length代表数组长度
int FindOneNumber(int* a, int length)
{
    int candidate = a[0];
    int nTimes = 1;
    for (int i = 1; i < length; i++)
    {
        if (nTimes == 0)
        {
            candidate = a[i];
            nTimes = 1;
        }
        else
        {
            if (candidate == a[i])
                nTimes++;
            else
                nTimes--;
        }
    }
    return candidate;
}
