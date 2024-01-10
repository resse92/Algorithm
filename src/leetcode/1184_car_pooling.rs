use super::util::solution::Solution;

// https://leetcode.cn/problems/car-pooling/

impl Solution {
    pub fn car_pooling(trips: Vec<Vec<i32>>, capacity: i32) -> bool {
        let mut remaining = vec![0; 1001];
        for trip in trips {
            let num_passagers = trip[0];
            let from = trip[1];
            let to = trip[2];
            for i in from..to {
                remaining[i as usize] += num_passagers;
                if remaining[i as usize] > capacity {
                    return false;
                }
            }
        }
        true
    }

    // 差分数组
    // 利用差分数组性质，首尾两点O(1)时间批量同步更新区间内各点值。
    // 构建囊括所有行车范围的差分数组diff，diff[i]代表实际行驶过程中i点车上需要搭载乘客数量，初始值为0。
    // 遍历trips，按照差分数组构造方法将trips[i]的乘客数量trips[i][0]加到对应区间[trips[i][1],trips[i][2]]，
    // 之后sum从头开始累加diff各点值，就得到了对应地点车上需要搭载的乘客数量，
    // 若行驶(累加)过程中sum > cap说明乘客超额，该路段乘客无法全部上车到达目的地，返回false。
    // 注意每个地点若有下车的乘客，则下车的部分乘客不计入该位置车内容量，即构造diff时，区间尾部需要在p[2]处减去乘客数量，而不是p[2]+1处。
    pub fn car_pooling1(trips: Vec<Vec<i32>>, capacity: i32) -> bool {
        let mut diff = vec![0; 1001];
        for trip in trips {
            let num_passagers = trip[0];
            let from = trip[1];
            let to = trip[2];
            diff[from as usize] += num_passagers;
            diff[to as usize] -= num_passagers;
        }

        let mut sum = 0;
        for d in diff {
            sum += d;
            if sum > capacity {
                return false;
            }
        }
        true
    }
}
