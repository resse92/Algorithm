fn swap(nums: &mut Vec<i32>, left: usize, right: usize) {
    let tmp = nums[right];
    nums[right] = nums[left];
    nums[left] = tmp
}

fn partition(nums: &mut Vec<i32>, i: usize, j: usize) -> usize {
    let mut left = i;
    let mut right = j;
    while left < right {
        while left < right && nums[left] < nums[i] {
            left += 1;
        }
        while left < right && nums[right] >= nums[i] {
            right -= 1;
        }
        swap(nums, left, right);
    }
    swap(nums, i, left);

    left
}

fn quick_sort(nums: &mut Vec<i32>) {
    fn qs(nums: &mut Vec<i32>, left: usize, right: usize) {
        if left >= right {
            return;
        }
        let pivot = partition(nums, left, right);
        if pivot >= 1 {
            qs(nums, left, pivot - 1);
        }
        qs(nums, pivot + 1, right);
    }

    qs(nums, 0, nums.len() - 1);
}

#[test]
fn test_quick_test() {
    let mut nums: Vec<i32> = vec![3, 4, 9, 1, 5];
    quick_sort(&mut nums);
    assert!(nums == [1, 3, 4, 5, 9]);
}
