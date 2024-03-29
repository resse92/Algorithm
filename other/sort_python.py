# 排序算法
#

from typing import List

# 冒泡排序
# 步骤: 比较相邻的元素,如果前一个比后一个大,则调换两个位置,第一轮完了之后,最后的数是最大的,第二轮继续,除了最后一个数,一次循环下去


def exchange(array, index1, index2):
    # temp = array[index1]
    # array[index1] = array[index2]
    # array[index2] = temp
    array[index1], array[index2] = array[index2], array[index1]


def bubble_sort1(numArray):
    x = 1
    i = 0
    length = len(numArray)

    for i in range(1, length):
        for j in range(0, length - i):
            if numArray[j] > numArray[j + 1]:
                exchange(numArray, j, j + 1)
    print(numArray)


def bubble_sort2(lists):
    # 冒泡排序
    count = len(lists)
    for i in range(0, count):
        for j in range(i + 1, count):
            if lists[i] > lists[j]:
                lists[i], lists[j] = lists[j], lists[i]
    return lists


# 鸡尾酒排序(定向冒泡排序)
# 冒泡排序的一种改进算法, 从低到高排序后,从高到低开始排序
def cocktail_sort(numArray):
    length = len(numArray)
    left = 0
    right = length - 1
    while left < right:
        for i in range(left, right):  # 前半轮,将最大的放在右边
            if numArray[i] > numArray[i + 1]:
                exchange(numArray, i, i + 1)
        right -= 1

        for j in reversed(range(left + 1, right + 1)):  # 后半轮,将最小的放在左边
            if numArray[j - 1] > numArray[j]:
                exchange(numArray, j - 1, j)
        left += 1


# 选择排序
# 两个序列,从未排序序列中找到最小值,放入排序序列第一个,再从剩下未排序序列中找最小值放入排序序列最后,依次这样
def selection_sort(numArray):
    length = len(numArray)
    i = 0
    j = length - 1
    for i in range(i, length):  # 已排序序列的末尾
        minx = i
        for j in range(i, length):  # 未排序序列
            if numArray[j] < numArray[minx]:
                minx = j

        if minx != i:
            exchange(numArray, minx, i)


# 插入排序
# 从第一个元素开始,该元素可以认为已经被排序,取出下一个元素,在1已经排序的元素序列中从后向前扫描
# 如果该元素(已排序)大于新元素,将该元素移动到下一位置,重复这一步直到已排序的元素小于或者等于新元素的位置
# 将新元素插入到该位置后,再重复以上步骤
def insert_sort(numArray):
    length = len(numArray)
    for i in range(1, length):
        get = numArray[i]  # 类似抓扑克排序
        j = i - 1  # 拿在左手上的牌总是排序好的
        while (j >= 0) and (numArray[j] > get):  # 将抓到的牌与手牌从左向右进行比较
            numArray[j + 1] = numArray[j]  # 如果该手牌比抓到的牌大,将其右移
            j -= 1
        numArray[j + 1] = get  # 直到该手牌比抓到的牌小(或者相等),将抓到的牌插入手牌右边(相等元素的相对次序未变,所以是稳定的)


# 二分插入排序(插入排序的改进)
# 可以用二分查找发减少比较操作的数目
def binary_search_insert_select(numArray):
    n = len(numArray)
    right = 0
    left = 0
    for i in range(0, n):
        get = numArray[i]
        left = 0
        right = i - 1
        while left <= right:
            middle = int((left + right) / 2)
            if numArray[middle] > get:
                right = middle - 1
            else:
                left = middle + 1
        for j in reversed(range(left, i)):
            numArray[j + 1] = numArray[j]
        numArray[left] = get


# 希尔排序(插入排序的更高效改进,又名递减增量排序,不稳定)
# 通过将比较的全部元素分为几个区域来提升插入排序的性能


def shell_sort(lists):
    # 希尔排序
    count = len(lists)
    step = 2
    group = count // step  # //为floor除法,不保留小数
    while group > 0:
        for i in range(0, group):
            j = i + group
            while j < count:
                k = j - group
                key = lists[j]
                while k >= 0:
                    if lists[k] > key:
                        lists[k + group] = lists[k]
                        lists[k] = key
                    k -= group
                j += group
        group //= step
    return lists


# 归并排序
# 指将两个已经排序的序列合并成一个序列的操作
# 1. 申请空间,使其大小为两个已经排序序列之和,该空间用来存放合并后的序列
# 2. 设定两个指针,最初位置为两个已经排序序列的起始位置
# 3. 比较两个指针所指向的元素,选择相对小的元素放入合并空间,并移动到下一位置
# 4. 重复第三部,直到到达序列尾
# 5. 将另一序列剩下的所有元素直接复制到合并序列尾
def merge_sort(numArray):
    if len(numArray) <= 1:
        return numArray
    num = len(numArray) // 2
    left = merge_sort(numArray[:num])
    right = merge_sort(numArray[num:])
    return merge(left, right)


def merge(left, right):
    i, j = 0, 0
    result = []
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result += left[i:]
    result += right[j:]
    return result


# 堆排序
# 利用堆这种数据结构所设计的排序算法,堆是一个近似完全二叉树的结构,同时满足堆的性质:即子节点的键值总是小于(或者大于)它的父节点
# 1. 创建一个堆
# 2. 把堆顶元素(最大值)和堆尾元素互换
# 3. 把堆的尺寸缩小1,并调用heapify(A, 0)从新的对顶元素开始进行堆调整
# 4. 重复步骤2,知道堆的尺寸为1
def adjust_heap(lists, i, size):
    lchild = 2 * i + 1
    rchild = 2 * i + 2
    maxx = i
    if i < size // 2:
        if lchild < size and lists[lchild] > lists[maxx]:
            maxx = lchild
        if rchild < size and lists[rchild] > lists[maxx]:
            maxx = rchild
        if maxx != i:
            lists[maxx], lists[i] = lists[i], lists[maxx]
            adjust_heap(lists, maxx, size)


def build_heap(lists, size):
    for i in range(0, (size // 2))[::-1]:
        adjust_heap(lists, i, size)


def heap_sort(lists):
    size = len(lists)
    build_heap(lists, size)
    for i in range(0, size)[::-1]:
        lists[0], lists[i] = lists[i], lists[0]
        adjust_heap(lists, 0, i)


# 快速排序
# 采用分而治之的策略,把一个序列分成两个子序列
# 1. 从序列中挑出一个元素作为"基准"(pivot)
# 2. 把所有比基准值小的元素放在基准面前,所有比基准大的值放在后面(相同的数放任意一边), 这个称为分区操作
# 3. 对每个分区递归的进行步骤1~3,递归结束的条件是0或1,这时整体已经排好序了
def quick_sort(lists, left, right):
    # 快速排序
    if left >= right:
        return lists
    key = lists[left]
    low = left
    high = right
    while left < right:
        while left < right and lists[right] >= key:
            right -= 1
        lists[left] = lists[right]
        while left < right and lists[left] <= key:
            left += 1
        lists[right] = lists[left]
    lists[right] = key
    quick_sort(lists, low, left - 1)
    quick_sort(lists, left + 1, high)
    return lists


# 快速排序双指针法
def quick_sort2(lists: List[int]):
    if len(lists) <= 1:
        return lists
    left, right = 0, len(lists) - 1
    while left < right:
        while left < right and lists[right] >= lists[0]:
            right -= 1
        while left < right and lists[left] <= lists[0]:
            left += 1
        lists[left], lists[right] = lists[right], lists[left]
    lists[0], lists[left] = lists[left], lists[0]
    return quick_sort2(lists[:left]) + [lists[left]] + quick_sort2(lists[left + 1 :])


# 基数排序

# 基数排序（radix sort）属于“分配式排序”（distribution sort），
# 又称“桶子法”（bucket sort）或bin sort，
# 顾名思义，它是透过键值的部份资讯，将要排序的元素分配至某些“桶”中，藉以达到排序的作用，
# 基数排序法是属于稳定性的排序，其时间复杂度为O (nlog(r)m)，其中r为所采取的基数，而m为堆数，在某些时候，基数排序法的效率高于其它的稳定性排序法。
import math


def radix_sort(lists, radix=10):
    k = int(math.ceil(math.log(max(lists), radix)))
    bucket = [[] for i in range(radix)]
    for i in range(1, k + 1):
        for j in lists:
            bucket[j // (radix ** (i - 1)) % (radix**i)].append(j)
        del lists[:]
        for z in bucket:
            lists += z
            del z[:]
    return lists


import random


def main():
    ha = []
    for i in range(0, 40):
        ha.append(random.randint(0, 99))
    print(ha)
    # quick_sort(ha)
    # print(radix_sort(ha))
    print(quick_sort2(ha))
    print(ha)


main()


def reverseLeftWords(s: str, n: int) -> str:
    l = len(s)
    res = s[-n - 1 :] + s[0 : l - n]
    return res
