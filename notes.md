# 你又假装记笔记？

173 BST Iterator

560 Subarray Sum

一种暴力解法是求出1~i(i=1,2,...,n)的子序列和，然后用减法枚举，事实上这比无脑暴力还多了O(n)的存储，不过两数之差=k可以用map/unordered_map加速。嗯，和求出数组中两数之和为s的组合数那道题思路一样，不过这里做了一层预处理

unordered_map取单值会比map快点，不过遍历稍慢？说到底是个哈希，给我一种听天由命的赶脚...
> <http://www.cplusplus.com/reference/unordered_map/unordered_map/>
> unordered_map containers are faster than map containers to access individual elements by their key, although they are generally less efficient for range iteration through a subset of their elements.

42 Trap

对于每一个格子，蓄水量为左右最高的格子的次小者减去自身高度。那个迭代还是挺精妙的，剪枝意味浓厚
