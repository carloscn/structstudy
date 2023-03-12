# Leetcode and Algo Daily Training

## Direction
截止到2023年3月10日，做以下规则变更：
* 不再RUST和C进行同步；
* 为了熟悉RUST语言，RUST继续进行leetcode简单等级的题目；
* 为了熟悉算法及数据结构的使用，使用C进行leetcode的中等的题目；
* C按照算法及数据结构的类别进行专题刷；
* RUST延续C的简单题目顺序继续往下进行。
## [基本数据结构的C语言实现](https://github.com/carloscn/structstudy/tree/master/c_programming/utils)
C语言无法像是高级计算机语言对基础数据结构有一部分的实现，而一些算法需要基于这些数据结构，故在本工程中的utils中实现基本的数据结构，在算法实现中可以调用这些数据结构的基本方法。通过接口封装的方式，可以轻松调用这些方法，基本数据结构还在扩充中。
* [栈（stack）](https://github.com/carloscn/structstudy/blob/master/c_programming/utils/stack.c)
* [队列（queue）](https://github.com/carloscn/structstudy/blob/master/c_programming/utils/queue.c)
* [链表（linkedlist）](https://github.com/carloscn/structstudy/blob/master/c_programming/utils/linklist.c)
* [字符串列表（stringlist）](https://github.com/carloscn/structstudy/blob/master/c_programming/utils/strlist.c)
* [动态数组（buffer）](https://github.com/carloscn/structstudy/blob/master/c_programming/utils/buffer.c)
* [动态数组列表(bufferlist)](https://github.com/carloscn/structstudy/blob/master/c_programming/utils/bufferlist.c)
* [二叉树/堆（binarytree/heap）](https://github.com/carloscn/structstudy/blob/master/c_programming/utils/binary_tree.c)
* [多叉树/堆（multitree/heap）](https://github.com/carloscn/structstudy/blob/master/c_programming/utils/multi_tree.c)
* [哈希映射表（hash mapping）](https://github.com/carloscn/structstudy/blob/master/c_programming/utils/hash_map.c)
## [数组](https://github.com/carloscn/structstudy/tree/master/c_programming/array)：
* [在数组中查找元素](https://github.com/carloscn/structstudy/issues/1)
* [调整数组顺序使奇数位于偶数前面（冒泡排序）](https://github.com/carloscn/structstudy/issues/2)
* [数组中次数出现超过一半的数字（摩尔投票法）](https://github.com/carloscn/structstudy/issues/3)
* [连续子数组的最大和 （思维与技巧)](https://github.com/carloscn/structstudy/issues/4)
* [数组中重复的数字（数组值在数组索引范围内）（思维与技巧）](https://github.com/carloscn/structstudy/issues/5)
* [数组中重复的数字（不修改原始数组）（二分法）](https://github.com/carloscn/structstudy/issues/6)
* [在二维数组中的查找（思维与技巧）](https://github.com/carloscn/structstudy/issues/7)
* [排序][对数组内的元素进行排序（冒泡排序法)](https://github.com/carloscn/structstudy/issues/9)
* [排序][对数组内的元素进行排序（选择排序法)](https://github.com/carloscn/structstudy/issues/10)
* [排序][对数组内的元素进行排序（插入排序法)](https://github.com/carloscn/structstudy/issues/11)
* [排序][递归][对数组内的元素进行排序（快速排序法)](https://github.com/carloscn/structstudy/issues/12)
* [两数之和（leetcode-1）](https://github.com/carloscn/structstudy/issues/27) [2022-10-13]
* [用栈实现队列（leetcode-232）implement-queue-using-stacks](https://github.com/carloscn/structstudy/issues/29) [2022-10-14]
* [用队列实现栈（leetcode-225）implement-stack-using-queues](https://github.com/carloscn/structstudy/issues/30) [2022-10-14]
* [颜色分类-荷兰三色旗（leetcode-75）sort-colors](https://github.com/carloscn/structstudy/issues/32) [2022-10-15]
* [leetcode26：删除有序数组中的重复项（remove-duplicates-from-sorted-array）](https://github.com/carloscn/structstudy/issues/38) [2022-10-24]
* [leetcode27：移除元素（remove-element）](https://github.com/carloscn/structstudy/issues/39) [2022-10-25]
* [leetcode35：搜索插入位置（search-insert-position）](https://github.com/carloscn/structstudy/issues/40) [2022-10-26]
* [leetcode66：加一（plus-one）](https://github.com/carloscn/structstudy/issues/41) [2022-10-27]
* [leetcode88：合并两个有序数组（merge-sorted-array）](https://github.com/carloscn/structstudy/issues/46) [2022-10-31]
* [leetcode118：杨辉三角（pascals-triangle）](https://github.com/carloscn/structstudy/issues/47) [2022-11-01]
* [leetcode119：杨辉三角 II（pascals-triangle-ii）](https://github.com/carloscn/structstudy/issues/48) [2022-11-02]
* [leetcode121：买卖股票的最佳时机（best-time-to-buy-and-sell-stock）](https://github.com/carloscn/structstudy/issues/49) [2022-11-03]
* [leetcode136：只出现一次的数字（single-number）](https://github.com/carloscn/structstudy/issues/50) [2022-11-04]
* [leetcode169：多数元素（majority-element）](https://github.com/carloscn/structstudy/issues/54) [2022-11-08]
* [leetcode217：存在重复元素（contains-duplicate）](https://github.com/carloscn/structstudy/issues/63) [2022-11-17]
* [leetcode11：盛最多水的容器（container-with-most-water）](https://github.com/carloscn/structstudy/issues/65) [2022-11-19]
* [leetcode15：三数之和（3sum）](https://github.com/carloscn/structstudy/issues/66) [2022-11-20]
* [leetcode228：汇总区间（summary-ranges）](https://github.com/carloscn/structstudy/issues/67) [2022-11-21]
* [leetcode268：丢失的数字（missing-number）](https://github.com/carloscn/structstudy/issues/71) [2022-11-25]
* [leetcode278：第一个错误的版本（first-bad-version）](https://github.com/carloscn/structstudy/issues/73) [2022-11-28]
* [leetcode283：移动零元素（move-zeroes）](https://github.com/carloscn/structstudy/issues/74) [2022-11-29]
* [leetcode18：四数之和（4sum）](https://github.com/carloscn/structstudy/issues/78) [2022-12-04]
* [leetcode338：比特位计数（counting-bits）](https://github.com/carloscn/structstudy/issues/80) [2022-12-06]
* [leetcode349：两个数组的交集（intersection-of-two-arrays）](https://github.com/carloscn/structstudy/issues/84) [2022-12-11]
* [leetcode448：找到所有数组中消失的数字（find-all-numbers-disappeared-in-an-array）](https://github.com/carloscn/structstudy/issues/99) [2023-01-14]
* [leetcode455：分发饼干（assign-cookies）](https://github.com/carloscn/structstudy/issues/100) [2023-01-15]
* [leetcode463：岛屿的周长（island-perimeter）](https://github.com/carloscn/structstudy/issues/103) [2023-01-18]
* [leetcode485：最大连续1的个数（max-consecutive-ones）](https://github.com/carloscn/structstudy/issues/106) [2023-01-22]
* [leetcode492：构造矩形（construct-the-rectangle）](https://github.com/carloscn/structstudy/issues/107) [2023-01-23]
* [leetcode495：提莫攻击（teemo-attacking） ](https://github.com/carloscn/structstudy/issues/108) [2023-01-24]
* [leetcode496：下一个更大元素 I（next-greater-element-i）](https://github.com/carloscn/structstudy/issues/109) [2023-01-28]
* [leetcode506：相对名次（relative-ranks）](https://github.com/carloscn/structstudy/issues/112) [2023-02-01]
* [leetcode643：子数组最大平均数 I（maximum-average-subarray-i）](https://github.com/carloscn/structstudy/issues/116) [2023-02-06]
* [leetcode645：错误的集合（set-mismatch）](https://github.com/carloscn/structstudy/issues/117) [2023-02-07]
* [leetcode674：最长连续递增序列（longest-continuous-increasing-subsequence）](https://github.com/carloscn/structstudy/issues/119) [2023-02-09]
* [leetcode697：数组的度（degree_of_an_array_697）](https://github.com/carloscn/structstudy/issues/123) [2023-02-13]
* [leetcode724：寻找数组的中心下标（find_pivot_index_724）](https://github.com/carloscn/structstudy/issues/125) [2023-02-17]
* [leetcode746：使用最小花费爬楼梯（min_cost_climbing_stairs_746）](https://github.com/carloscn/structstudy/issues/127) [2023-02-19]
* [leetcode747：至少是其他数字两倍的最大数（largest_number_at_least_twice_of_others_747）](https://github.com/carloscn/structstudy/issues/128) [2023-02-20]
* [leetcode766：托普利茨矩阵（toeplitz_matrix_766）](https://github.com/carloscn/structstudy/issues/130) [2023-02-23]
* [leetcode821：字符的最短距离（shortest_distance_to_a_character_821）](https://github.com/carloscn/structstudy/issues/134) [2023-02-27]
* [leetcode34：在排序数组中查找元素的第一个和最后一个位置（find_first_and_last_position_of_element_in_sorted_array_34）](https://github.com/carloscn/structstudy/issues/136) [2023-02-28]
* [leetcode38：外观数列（count-and-say）](https://github.com/carloscn/structstudy/issues/137) [2023-03-02]
* [leetcode832：翻转图像（flipping_an_image_832](https://github.com/carloscn/structstudy/issues/145) [2023-03-12]
## [字符串](https://github.com/carloscn/structstudy/tree/master/c_programming/str)：
* [替换字符串空格（双指针法）](https://github.com/carloscn/structstudy/issues/8)
* [最后一个单词的长度 (leetcode-58) ](https://github.com/carloscn/structstudy/issues/26) [2022-10-12]
* [回文数(leetcode-9）](https://github.com/carloscn/structstudy/issues/28) [2022-10-13]
* [罗马数字转整数（leetcode-13）roman-to-integer](https://github.com/carloscn/structstudy/issues/33) [2022-10-17]
* [最长公共前缀（leetcode-14）longest-common-prefix](https://github.com/carloscn/structstudy/issues/34) [2022-10-17]
* [有效的括号（leetcode-20）valid-parentheses](https://github.com/carloscn/structstudy/issues/35) [2022-10-18]
* [无重复字符的最长子串（leetcode-3）longest-substring-without-repeating-characters](https://github.com/carloscn/structstudy/issues/36) [2022-10-18]
* [leetcode67：二进制求和（add-binary）](https://github.com/carloscn/structstudy/issues/42) [2022-10-28]
* [leetcode168：Excel表列名称（excel-sheet-column-title）](https://github.com/carloscn/structstudy/issues/53) [2022-11-07]
* [leetcode171：Excel 表列序号（excel-sheet-column-number）](https://github.com/carloscn/structstudy/issues/55) [2022-11-09]
* [leetcode190：颠倒二进制（reverse-bits）](https://github.com/carloscn/structstudy/issues/56) [2022-11-10]
* [leetcode191：位1的个数（number-of-1-bits）](https://github.com/carloscn/structstudy/issues/57) [2022-11-11]
* [leetcode8：字符串转换整数 (atoi)](https://github.com/carloscn/structstudy/issues/59) [2022-11-13]
* [leetcode205：同构字符串（isomorphic-strings）](https://github.com/carloscn/structstudy/issues/62) [2022-11-16]
* [leetcode242：有效的字母异位词（valid-anagram）](https://github.com/carloscn/structstudy/issues/69) [2022-11-23]
* [leetcode290：单词规律（word-pattern）](https://github.com/carloscn/structstudy/issues/75) [2022-11-30]
* [leetcode17：电话号码的字母组合（letter-combinations-of-a-phone-number）](https://github.com/carloscn/structstudy/issues/77) [2022-12-03]
* [leetcode344：反转字符串（reverse-string）](https://github.com/carloscn/structstudy/issues/82) [2022-12-09]
* [leetcode345：反转字符串中的元音字母（reverse-vowels-of-a-string）](https://github.com/carloscn/structstudy/issues/83) [2022-12-10]
* [leetcode383：赎金信（ransom-note）](https://github.com/carloscn/structstudy/issues/87) [2022-12-15]
* [leetcode389：找不同（find-the-difference）](https://github.com/carloscn/structstudy/issues/89) [2022-12-18]
* [leetcode392：判断子序列（is-subsequence](https://github.com/carloscn/structstudy/issues/90) [2022-12-20]
* [leetcode401：二进制手表（binary-watch）](https://github.com/carloscn/structstudy/issues/91) [2022-12-21]
* [leetcode405：数字转换为十六进制数（convert-a-number-to-hexadecimal）](https://github.com/carloscn/structstudy/issues/92) [2022-12-23]
* [leetcode409：最长回文串（longest-palindrome](https://github.com/carloscn/structstudy/issues/93) [2022-12-24]
* [leetcode412：Fizz Buzz](https://github.com/carloscn/structstudy/issues/94) [2022-12-25]
* [leetcode414：第三大的数（third-maximum-number）](https://github.com/carloscn/structstudy/issues/95) [2023-01-03]
* [leetcode415：字符串相加（add-strings）](https://github.com/carloscn/structstudy/issues/96) [2023-01-07]
* [leetcode434：字符串中的单词数（number-of-segments-in-a-string）](https://github.com/carloscn/structstudy/issues/97) [2023-01-08]
* [leetcode441：排列硬币（arranging-coins）](https://github.com/carloscn/structstudy/issues/98) [2023-01-10]
* [leetcode459：重复的子字符串（repeated-substring-pattern）](https://github.com/carloscn/structstudy/issues/101) [2023-01-16]
* [leetcode482：密钥格式化（license-key-formatting）](https://github.com/carloscn/structstudy/issues/105) [2023-01-21]
* [leetcode500：键盘行（keyboard-row）](https://github.com/carloscn/structstudy/issues/110) [2023-01-30]
* [leetcode504：七进制数（base-7）](https://github.com/carloscn/structstudy/issues/111) [2023-01-31]
* [leetcode520：检测大写字母（detect-capital）](https://github.com/carloscn/structstudy/issues/113) [2023-02-03]
* [leetcode521：最长特殊序列I（longest-uncommon-subsequence-i）](https://github.com/carloscn/structstudy/issues/114) [2023-02-04]
* [leetcode541：反转字符串 II（reverse-string-ii）](https://github.com/carloscn/structstudy/issues/115) [2023-02-5]
* [leetcode657：机器人能否返回原点（robot-return-to-origin）](https://github.com/carloscn/structstudy/issues/118) [2023-02-08]
* [leetcode680：验证回文串 II（valid_palindrome_ii）](https://github.com/carloscn/structstudy/issues/120) [2023-02-10]
* [leetcode696：计数二进制字符串（count-binary-substrings）](https://github.com/carloscn/structstudy/issues/122) [2023-02-12]
* [leetcode709：转换成小写字母（to_lower_case_709](https://github.com/carloscn/structstudy/issues/124) [2023-02-15]
* [leetcode744：寻找比目标字母大的最小字母（find_smallest_letter_greater_than_target_744）](https://github.com/carloscn/structstudy/issues/126) [2023-02-18]
* [leetcode748：最短补全词（shortest_completing_word_748）](https://github.com/carloscn/structstudy/issues/129) [2023-02-21]
* [leetcode771：宝石与石头（jewels-and-stones）](https://github.com/carloscn/structstudy/issues/131) [2023-02-24]
* [leetcode796：旋转字符串（rotate-string）](https://github.com/carloscn/structstudy/issues/132) [2023-02-25]
* [leetcode819：最常见的单词（most_common_word_819）](https://github.com/carloscn/structstudy/issues/133) [2023-02-26]
* [leetcode28：找出字符串中第一个匹配项的下标（find_the_index_of_the_first_occurrence_in_a_string_28）](https://github.com/carloscn/structstudy/issues/135) [2023-02-27]
* [leetcode43：字符串相乘（multiply_strings_43）](https://github.com/carloscn/structstudy/issues/140) [2023-03-07]
* [leetcode824：山羊拉丁文（goat_latin_824）](https://github.com/carloscn/structstudy/issues/142) [2023-03-10]
* [leetcode830：较大分组的位置（positions_of_large_groups_830）](https://github.com/carloscn/structstudy/issues/143) [2023-03-11]
## [链表](https://github.com/carloscn/structstudy/tree/master/c_programming/linklist)：
* [删除链表的节点](https://github.com/carloscn/structstudy/issues/15)
* [反转链表（leetcode-206）reverse-linked-list](https://github.com/carloscn/structstudy/issues/31) [2022-10-14]
* [leetcode-21：合并两个有序链表（merge-two-sorted-lists）](https://github.com/carloscn/structstudy/issues/37) [2022-10-23]
* [leetcode83：删除排序链表中的重复元素（remove-duplicates-from-sorted-list）](https://github.com/carloscn/structstudy/issues/45) [2022-10-30]
* [leetcode141：环形链表（linked-list-cycle）](https://github.com/carloscn/structstudy/issues/51) [2022-11-05]
* [leetcode160：相交链表（intersection-of-two-linked-lists）](https://github.com/carloscn/structstudy/issues/52) [2022-11-06]
* [leetcode203：移除链表元素（remove-linked-list-elements）](https://github.com/carloscn/structstudy/issues/61) [2022-11-15]
## [数学](https://github.com/carloscn/structstudy/tree/master/c_programming/common)：
* [数值的整数次方](https://github.com/carloscn/structstudy/issues/13)
* [打印从1到最大的n位数(含回溯方法)](https://github.com/carloscn/structstudy/issues/14)
* [leetcode69：x的平方根（sqrtx）](https://github.com/carloscn/structstudy/issues/43) [2022-10-28]
* [leetcode7：整数反转（reverse-integer）](https://github.com/carloscn/structstudy/issues/58) [2022-11-12]
* [leetcode202：快乐数（happy-number）](https://github.com/carloscn/structstudy/issues/60) [2022-11-14]
* [leetcode231：2 的幂（power-of-two）](https://github.com/carloscn/structstudy/issues/68) [2022-11-22]
* [leetcode258：各位相加（add-digits)](https://github.com/carloscn/structstudy/issues/70) [2022-11-24]
* [leetcode292：Nim 游戏（nim-game）](https://github.com/carloscn/structstudy/issues/76) [2022-12-02]
* [leetcode326：3 的幂（power-of-three）](https://github.com/carloscn/structstudy/issues/79) [2022-12-05]
* [leetcode342：4的幂（power-of-four）](https://github.com/carloscn/structstudy/issues/81) [2022-12-08]
* [leetcode367：有效的完全平方数（valid-perfect-square）](https://github.com/carloscn/structstudy/issues/85) [2022-12-13]
* [leetcode374：猜数字大小（guess-number-higher-or-lower）](https://github.com/carloscn/structstudy/issues/86) [2022-12-14]
* [leetcode461：汉明距离（hamming-distance）](https://github.com/carloscn/structstudy/issues/102) [2023-01-17]
* [leetcode476：数字的补数（number-complement）](https://github.com/carloscn/structstudy/issues/104) [2023-01-25]
* [leetcode693：交替位二进制数（binary-number-with-alternating-bits）](https://github.com/carloscn/structstudy/issues/121) [2023-02-11]
## [二叉树](https://github.com/carloscn/structstudy/tree/master/c_programming/tree)
* [二叉树的层次/前序/中序/后续遍历](https://github.com/carloscn/structstudy/issues/22)
* [二叉树展开为链表（leetcode-114）](https://github.com/carloscn/structstudy/issues/23)
* [二叉树的所有路径（leetcode-257）](https://github.com/carloscn/structstudy/issues/24)
* [二叉搜索树中第K小的元素（leetcode-230）](https://github.com/carloscn/structstudy/issues/25)
## [递归回溯问题](https://github.com/carloscn/structstudy/tree/master/c_programming/recuirsion)
* [斐波那契数列(Fibonacci)的第n项](https://github.com/carloscn/structstudy/issues/16)
* [生成匹配的括号(Leetcode-22)](https://github.com/carloscn/structstudy/issues/17)
* [所有子集(leetcode-78)](https://github.com/carloscn/structstudy/issues/18)
* [复原IP地址(leetcode-93)](https://github.com/carloscn/structstudy/issues/19)
* [包含k个元素的组合(leetcode-77)](https://github.com/carloscn/structstudy/issues/20)
* [字典序排数(leetcode-386)](https://github.com/carloscn/structstudy/issues/21)
* [leetcode70：爬楼梯（climbing-stairs）](https://github.com/carloscn/structstudy/issues/44) [2022-10-29]
* [leetcode39：组合总和（combination_sum_39）](https://github.com/carloscn/structstudy/issues/138) [2023-03-03]
* [leetcode40：组合总和 II（combination-sum-ii）](https://github.com/carloscn/structstudy/issues/139) [2023-03-06]
* [leetcode45： 跳跃游戏 II（jump-game-ii）](https://github.com/carloscn/structstudy/issues/141) [2023-03-11]
## 贪心算法
* [leetcode376：摆动序列（wiggle_subsequence）](https://github.com/carloscn/structstudy/issues/144) [2023-03-12]