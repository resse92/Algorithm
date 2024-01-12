use super::util::solution::Solution;

// https://leetcode.cn/problems/make-number-of-distinct-characters-equal/description/

impl Solution {
    pub fn is_it_possible(word1: String, word2: String) -> bool {
        let mut cnt_word1 = vec![0; 26];
        let mut cnt_word2 = vec![0; 26];
        let mut count1 = 0;
        let mut count2 = 0;

        // 1. 统计字母的出现次数
        for c in word1.chars() {
            let idx = (c as u8 - 'a' as u8) as usize;
            cnt_word1[idx] += 1;
            if cnt_word1[idx] == 1 {
                count1 += 1;
            }
        }
        for c in word2.chars() {
            let idx = (c as u8 - 'a' as u8) as usize;
            cnt_word2[idx] += 1;
            if cnt_word2[idx] == 1 {
                count2 += 1;
            }
        }
        // 2. 枚举交换所有可能的字母，然后判断交换后的cnt_word1的非0元素是否等于cnt_word2的非0元素数目
        for i in 0..26 {
            for j in 0..26 {
                if cnt_word1[i] == 0 || cnt_word2[j] == 0 {
                    continue;
                }

                let mut count1 = count1;
                let mut count2 = count2;

                // cnt_word1[i]交换到cnt_word2[i]
                if cnt_word1[i] == 1 && i != j {
                    count1 -= 1;
                }
                if cnt_word2[i] == 0 {
                    count2 += 1;
                }

                // cnt_word2[j]交换到cnt_word1[j]
                if cnt_word2[j] == 1 && i != j {
                    count2 -= 1;
                }
                if cnt_word1[j] == 0 {
                    count1 += 1;
                }

                if count1 == count2 {
                    return true;
                }
            }
        }

        false
    }
}
