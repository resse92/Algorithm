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




class Test {
    
}





