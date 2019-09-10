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

581 Shortest Unsorted Subarray

关键是确定未排序子数组的出错左右位置，有点意思。比如要找出左边出错的位置，先判断相邻两数之间的序是否正确，如果不正确，找出从当前位置到最右的最小值，这便是左边出错的最小值，第二次扫描数组通过该数来确定出错的位置也就是该值应该在的位置。右边出错位置同理。

297 Deserialization and Serialization of BST

还行，树相关的东西应该首先想到递归的...另一种是编解码都借助一个队列，注意搞出来的数组不是完全二叉树，所以解码的时候还是要用队列。看起来队列法比递归的时空复杂度都要更优。

399 除法

做完预处理就是个dfs，很不熟练的dfs，数据格式别搞错...貌似DFS和dfs是为了加个visited？

416/90 回溯法生成可重复数组的子集

先做排序，在选取n个重复数时只取数组的前n位来避免重复，具体看90，两种写法。一种用一个last_index记录上一个加入子集的索引，另一个遍历判断。

15 3Sum

三重for优化成O(n^2)，有一个很重要的点是要去重，所以确定i后用双指针的时候，确定low的时候，high就是确定的。sum太小就加low，太大就减high，等于sum即push到结果数组并且同时加low减high。指针的修正也要注意下额...

76 滑动窗口/双指针

合法时左移，不合法时右移。为啥我还是不会双指针

312 戳爆气球

有点意思，dp，有点像矩阵链乘，首尾加1...

124 树最大路径和(任意节点到任意节点)

有点意思

84,85 直方图/最大矩形(直方图变体)

单调栈，维护一个单调栈，pop出来的元素不会对未来的结果产生贡献，有点难

Combinations 问题

tmd  
这种Combination有三种case  
可重复选择某数的排列(377)-> 0  
可重复选择某数的组合(39)-> i  
不可重复选择(原数组包含重复)的组合(40)-> i+1  
不可重复选择的组合(组合个数限制)(216)  
