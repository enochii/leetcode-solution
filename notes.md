# 你又假装记笔记？

173 BST Iterator

560 Subarray Sum

一种暴力解法是求出1~i(i=1,2,...,n)的子序列和，然后用减法枚举，事实上这比无脑暴力还多了O(n)的存储，不过两数之差=k可以用map/unordered_map加速。嗯，和求出数组中两数之和为s的组合数那道题思路一样，不过这里做了一层预处理

unordered_map取单值会比map快点，不过遍历稍慢？说到底是个哈希，给我一种听天由命的赶脚...
> <http://www.cplusplus.com/reference/unordered_map/unordered_map/>
> unordered_map containers are faster than map containers to access individual elements by their key, although they are generally less efficient for range iteration through a subset of their elements.

42 Trap

对于每一个格子，蓄水量为左右最高的格子的次小者减去自身高度。那个迭代还是挺精妙的，剪枝意味浓厚

160 List Intersection

求链表交集，思路有点巧，依次遍历比较两个组合链表，分别由两个输入链表按照不同的顺序首尾相连，思想基本算修正位移

337 rob III

强盗抢钱，求二叉树的最大部分和，要求不能同时取父子节点的值。不同的递归方式会导致有没有重复子问题出现，有点意思。不用计算重复子问题的版本就是在求的时候把一棵子树的两种和（是否包含自身）都返回。

我自己的傻逼版本问题就是把一棵树的两种情况分开求，导致不用记忆化的话会导致复杂度爆炸！
