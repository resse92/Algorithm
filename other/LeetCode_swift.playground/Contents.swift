//: Playground - noun: a place where people can play

import UIKit

var str = "Hello, playground"



///  Binary Tree Level Order Traversal
//------------------------------------------------------------------>


//public class TreeNode {
//     public var val: Int
//     public var left: TreeNode?
//     public var right: TreeNode?
//     public init(_ val: Int) {
//         self.val = val
//         self.left = nil
//         self.right = nil
//    }
//}
//
//
//class Solution {
//    
//    func levelOrder(_ root: TreeNode?) -> [[Int]] {
//        if root == nil {
//            return [[Int]]();
//        }
//        var res: [[Int]] = [[]]
//        var arr = [root]
//        while (arr.count != 0) {
//            let count = arr.count
//            var tmp: [Int]?
//            for _ in 0...count {
//                let x = arr[0]
//                arr.remove(at: 0)
//                tmp?.append(x!.val)
//                if x!.left != nil {
//                    arr.append(x!.left)
//                }
//                if x!.right != nil {
//                    arr.append(x!.right)
//                }
//            }
//            res.append((tmp)!)
//        }
//        return res
//    }
//}

///<-----------------------------------------------------



///  357. Count Numbers with Unique Digits
//------------------------------------------------------------------>
//class Solution1 {
//    func countNumbersWithUniqueDigits(_ n: Int) -> Int {
//        if n == 0 {
//            return 1;
//        }
//        let count = n < 11 ? n : 10
//        var resArr = 10
//        let lastNum = 9 - count + 2
//        var i = 9
//        var x = 9
//        while (x >= lastNum) {
//            i = i * x
//            resArr += i
//            x -= 1
//        }
//        return resArr
//    }
//}

///<-----------------------------------------------------

///234. Palindrome Linked List
//------------------------------------------------------------------>
//Definition for singly-linked list.

//public class ListNode {
//    public var val: Int
//    public var next: ListNode?
//    public init(_ val: Int) {
//        self.val = val
//        self.next = nil
//    }
//}
//
//class Solution2 {
//    func isPalindrome(_ head: ListNode?) -> Bool {
//        if head == nil {
//            return false
//        }
//        var arr = [head!.val]
//        var node = head!
//        while (node.next != nil) {
//            node = node.next!
//            arr.append(node.val)
//        }
//        
//        return arr == arr.reversed()
//    }
//}

///<-----------------------------------------------------


///---------------------------------------------------->
/// this is no leetcode question
/// learn dp with lis

class Lis1 {
    var lisArray:[Int] = []
    let primitiveArray = [2, 1, 6, 3, 5, 4, 8, 7, 9]
    
    init() {
        print(lis())
    }
    
    func lis() -> Int {
        for a in primitiveArray {
            lisArray.append(1)
            let index = primitiveArray.index(of: a)!
            for b in primitiveArray[0...index] {
                let indexB = primitiveArray.index(of: b)!
                // print("a=" + String(a))
                // print("b=" + String(b))
                // print(lisArray)
                // if b < a && lisArray[indexB] + 1 > lisArray[index]
                if a > b {
                    lisArray[index] = lisArray[indexB] + 1 > lisArray[index] ? lisArray[indexB]+1 : lisArray[index]
                }
            }
        }
        var max = 0
        for x in lisArray {
            if x > max {
                max = x
            }
        }
        return max
    }
    
}
//Lis1()
// 优化后O(nlogn)
class Lis2 {
    var lisArray:[Int] = []
    let primitiveArray = [2, 1, 6, 3, 5, 4, 8, 7, 9]
    var lisLen = 0
    
    init() {
        lis()
        print(111)
        print(lisArray)
    }
    
    func lis() -> Int {
        lisLen = 1
        lisArray.append(primitiveArray[0])
        
        for k in primitiveArray[1...primitiveArray.count-1] {
//            let index = primitiveArray.index(of: k)!
            print(lisLen)
            print(lisArray)
            if k > lisArray[lisLen - 1] { // k是否大于lisArray的最大元素
                lisArray.append(k)
                lisLen += 1
            } else {
                let pos = biSearch(lisArray, lisLen, k)
                print("pos=" + String(pos))
                if pos >= lisArray.count {
                    lisArray.append(k)
                } else {
                    lisArray[pos] = k
                }
            }
        }
        
        return 1
    }
    
    func biSearch(_ b: [Int], _ len: Int, _ w: Int) -> Int {
        var left = 0
        var right = len - 1
        print(left + (right - left) / 2)
        while left <= right {
            let mid = left + (right - left) / 2
            if lisArray[mid] > w {
                right = mid - 1
            } else if lisArray[mid] < w {
                left = mid + 1
            } else {
                return mid
            }
        }
        
        return left // 数组中不存在该元素，则返回应该插入的位置
    }
}
Lis2()

///<---------------------------------------------------

class Test {
    
}





