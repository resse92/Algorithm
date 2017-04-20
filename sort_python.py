#!/usr/bin/python
#-*-coding:utf-8-*-

# 排序算法

# 冒泡排序
# 步骤: 比较相邻的元素,如果前一个比后一个大,则调换两个位置,第一轮完了之后,最后的数是最大的,第二轮继续,除了最后一个数,一次循环下去

def exchange(array, index1, index2):
    temp = array[index1]
    array[index1] = array[index2]
    array[index2] = temp

def bubbleSort(numArray):
    x = 1
    i = 0
    while i < (len(numArray) - x) :
        if (numArray[i] > numArray[i + 1]):
            exchange(numArray, i, i + 1)
    print(numArray)

# 鸡尾酒排序(定向冒泡排序)
# 冒泡排序的一种改进算法, 从低到高排序后,从高到低开始排序
def cocktailSort(numArray):
    length = len(numArray)
    left = 0
    right = length - 1
    while left < right:
        i = left
        while i < right:
            if numArray[i] > numArray[i + 1]:
                exchange(numArray, i, i + 1)
            i += 1

        right -= 1

        i = right
        while i > left:
            if numArray[i - 1] > numArray[i]:
                exchange(numArray, i, i + 1)
            i -= 1
        left += 1

# 选择排序
# 两个序列,从未排序序列中找到最小值,放入排序序列第一个,再从剩下未排序序列中找最小值放入排序序列最后,依次这样
def selectionSort(numArray):
    length = len(numArray)
    i = 0
    j = length - 1
    while i <= length - 2: # 已排序序列的末尾
        minx = i
        while j <= length - 2: # 未排序序列
            if numArray[j] < numArray[minx]: # 依次找出未排序序列中的最小值,存放到已排序序列的末尾
                minx = j
            j += 1

        if min != i:
            exchange(numArray, min ,i) # 该操作很有可能把稳定性打乱,所以选择排序是不稳定的排序算法

        i += 1

# 插入排序
# 从第一个元素开始,该元素可以认为已经被排序,取出下一个元素,在1已经排序的元素序列中从后向前扫描
# 如果该元素(已排序)大于新元素,将该元素移动到下一位置,重复这一步直到已排序的元素小于或者等于新元素的位置
# 将新元素插入到该位置后,再重复以上步骤
def insertSort(numArray):
    length = len(numArray)
    i = 1
    j = 0
    get = 0

    while i < length: #类似抓扑克排序
        get = numArray[i] # 右手抓一张扑克牌
        j = i - 1 # 拿在左手上的牌总是排序好的
        while (j >= 0) and (numArray[j] > get): # 将抓到的牌与手牌从左向右进行比较
            numArray[j + 1] = numArray[j] # 如果该手牌比抓到的牌大,将其右移
            j -= 1

        numArray[j + 1] = get # 直到该手牌比抓到的牌小(或者相等),将抓到的牌插入手牌右边(相等元素的相对次序未变,所以是稳定的)
        i += 1

# 二分插入排序(插入排序的改进)
# 可以用二分查找发减少比较操作的数目
def binarySearchInsertSelect(numArray):
    n = len(numArray)
    i = 1
    j = i -1
    right = 0
    left = 0
    while i < n:
        get = numArray[i]
        left = 0
        right = i - 1
        while left <= right:
            middle = (left + right) / 2
            if numArray[middle] > get:
                right = middle - 1
            else:
                left = middle + 1

            j = i - 1
            while j >= left:
                numArray[j + 1] = numArray[j]
                j += 1
        i += 1
        numArray[left] = get

# 希尔排序(插入排序的更高效改进,又名递减增量排序,不稳定)
# 通过将比较的全部元素分为几个区域来提升插入排序的性能

def shellSort(numArray):
    n = len(numArray)
    i = 0
    j = 0
    get = 0
    h = 0

    while h <= n: # 生成初始增量
        h = 3 * h + 1

    i = h
    while h >= 1:
        while i < n:
            j = i - h
            get = numArray[i]
            while (j >= 0) and (numArray[j] > get):
                numArray[j + h] = numArray[j]
                j = j - h
            numArray[j + h] = get
            i += 1
        h = (h - 1) / 3 # 递减增量

# 归并排序
# 指将两个已经排序的序列合并成一个序列的操作
# 1. 申请空间,使其大小为两个已经排序序列之和,该空间用来存放合并后的序列
# 2. 设定两个指针,最初位置为两个已经排序序列的起始位置
# 3. 比较两个指针所指向的元素,选择相对小的元素放入合并空间,并移动到下一位置
# 4. 重复第三部,直到到达序列尾
# 5. 将另一序列剩下的所有元素直接复制到合并序列尾
def mergeSort(numArray):
    if len(numArray) <= 1:
        return numArray
    num = len(numArray) / 2
    left = mergeSort(numArray[:num])
    right = mergeSort(num[num:])
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
def adjustHeap(lists, i, size):
    lchild = 2 * i + 1
    rchild = 2 * i + 2
    max = i
    if i < size / 2:
        if lchild < size and lists[lchild] > lists[max]:
            max = lchild
        if rchild < size and lists[rchild] > lists[max]:
            max = rchild
        if max != i:
            lists[max], lists[i] = lists[i], lists[max]


def buildHeap(lists, size):
    for i in range(0, (size/2))[::-1]:

def heapSort(lists):
    size = len(lists)
    buildHeap(lists, size)
    for i in range(0, size)[::-1]:
        Lists[0], lists[i] = lists[i], lists[0]
        adjustHeap(lists, 0 i)
