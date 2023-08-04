// 构造大顶堆
fn heapify(nums: &mut Vec<i32>, n: usize, i: usize) {
    let mut index = i;
    let left_leaf = index * 2 + 1;
    let right_leaf = index * 2 + 2;
    if left_leaf < n && nums[left_leaf] > nums[index] {
        index = left_leaf;
    }

    if right_leaf < n && nums[right_leaf] > nums[index] {
        index = right_leaf;
    }

    if i != index {
        nums.swap(index, i);
        heapify(nums, n, index);
    }
}

fn heap_sort(nums: &mut Vec<i32>) {
    let n = nums.len();
    for i in (0..=(n / 2 - 1)).rev() {
        heapify(nums, n, i);
    }
    for i in (0..n).rev() {
        nums.swap(i, 0);
        heapify(nums, i, 0);
    }
}

#[test]
fn test_heap_sort() {
    let mut nums = vec![2, 3, 5, 10, 9];
    heap_sort(&mut nums);
    println!("{:?}", nums);
    assert!(nums == [2, 3, 5, 9, 10]);
    let mut nums = vec![7, 4, 8, 10, 2, 3, 9, 1];
    heap_sort(&mut nums);
    println!("{:?}", nums);
    assert!(nums == [1, 2, 3, 4, 7, 8, 9, 10]);
}
