use super::util::solution::Solution;

// https://leetcode.cn/problems/minimum-processing-time/

impl Solution {
    pub fn min_processing_time(processor_time: Vec<i32>, tasks: Vec<i32>) -> i32 {
        let n = processor_time.len();

        let mut processor_time = processor_time;
        // Sort processor_time in ascending order
        processor_time.sort();
        println!("{:?}", processor_time);
        let mut tasks = tasks;
        // Sort tasks in descending order
        tasks.sort_by(|a, b| b.cmp(a));
        println!("{:?}", tasks);

        let mut execution_time = vec![0; n];

        // for find the minimum time of all process, use greedy algorithm
        for (index, task) in tasks.iter().enumerate() {
            let i = index / 4;
            if i < n {
                execution_time[i] = execution_time[i].max(processor_time[i] + task);
            }
        }

        execution_time.iter().max().unwrap().clone()
    }
}
