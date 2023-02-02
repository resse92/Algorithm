use core::num;
use std::str::EncodeUtf16;

fn sort(nums: &mut Vec<i32>, start: usize, mid: usize, end: usize) {
    let mut t = Vec::new();
    for i in start..=end {
        t.push(nums[i]);
    }

    let mut i: usize = 0;
    let new_mid = mid - start;
    let mut j = new_mid + 1;
    let mut k = start;
    while i <= new_mid && j < t.len() {
        if t[i] <= t[j] {
            nums[k] = t[i];
            k += 1;
            i += 1;
        } else {
            nums[k] = t[j];
            k += 1;
            j += 1;
        }
    }

    while i <= new_mid {
        nums[k] = t[i];
        k += 1;
        i += 1;
    }
    while j < t.len() {
        nums[k] = t[j];
        k += 1;
        j += 1;
    }
}

fn merge(nums: &mut Vec<i32>, left: usize, right: usize) {
    if left >= right {
        return;
    }
    let mid = (left + right) / 2;
    merge(nums, left, mid);
    merge(nums, mid + 1, right);

    sort(nums, left, mid, right);
}

fn merge_sort(nums: &mut Vec<i32>) {
    merge(nums, 0, nums.len() - 1);
}

#[test]
fn test_merge_sort() {
    let mut nums = vec![2, 5, 3, 1, 9, 7, 6, 8];
    merge_sort(&mut nums);
    println!("{:?}", nums);
}
