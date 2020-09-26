'''
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

返回:

[
   [5,4,11,2],
   [5,8,4,5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from typing import List
import collections

# dfs
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        ret = list()
        path = list()

        def dfs(root: TreeNode, total: int):
            if not root:
                return
            path.append(root.val)
            total -= root.val
            if not root.left and not root.right and total == 0:
                ret.append(path[:])
            dfs(root.left, total)
            dfs(root.right, total)
            path.pop()

        dfs(root, sum)
        return ret

# bfs
class Solutoin:
    def pathSum(self, root: TreeNode, total: int) -> List[List[int]]:
        ret = list()
        parent = collections.defaultdict(lambda: None)
        
        def getPath(node: TreeNode):
            tmp = list()
            while node:
                tmp.append(node.val)
                node = parent[node]
            ret.append(tmp[::-1])

        if not root:
            return ret

        que_node = collections.deque([root])
        que_total = collections.deque([0])

        while que_node:
            node = que_node.popleft()
            rec = que_total.popleft() + node.val

            if not node.left and not node.right:
                if rec == total:
                    getPath(node)
                else:
                    if node.left:
                        parent[node.left] = node
                        que_node.append(node.left)
                        que_total.append(rec)
                    if node.right:
                        parent[node.right] = node
                        que_node.append(node.right)
                        que_total.append(rec)

        return ret
