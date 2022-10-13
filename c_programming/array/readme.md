# 数组相关的题目

本目录包含剑指offer的数组相关题目，可能在数组中会涉及一些算法的思想，包含：

*   数组查找 [01_find_array_element.c](https://github.com/carloscn/structstudy/blob/master/algo/array/src/01_find_array_element.c)
*   冒泡排序 [02_odd_find.c](https://github.com/carloscn/structstudy/blob/master/algo/array/src/02_odd_find.c)
*   摩尔投票法找到数组主要元素 [03_find_multi_ele.c](https://github.com/carloscn/structstudy/blob/master/algo/array/src/03_find_multi_ele.c)
*   在数组中找出重复元素https://github.com/carloscn/structstudy/blob/master/algo/array/src/05_find_repeat_value_in_array.c （可以修改数组）
*   在数组中找出重复元素https://github.com/carloscn/structstudy/blob/master/algo/array/src/06_find_repeat_values_in_array.c （不可以修改数组）
*   在二维数组中查找数组

## 题1：二维数组中的查找

##### 题目描述

>   在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

##### 例子

输入一个数组：

```C
num[3][4]=[
	1,4,6,28,
	2,7,32,30,
	10,11,67,79
]
```
需要查找一个数字32，则返回true。

数组查找 [01_find_array_element.c](https://github.com/carloscn/structstudy/blob/master/algo/array/src/01_find_array_element.c)

## 题2：剑指Offer（十三）--调整数组顺序使奇数位于偶数前面

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

冒泡排序 [02_odd_find.c](https://github.com/carloscn/structstudy/blob/master/algo/array/src/02_odd_find.c)

![image-20220817185517523](https://raw.githubusercontent.com/carloscn/images/main/typoraimage-20220817185517523.png)

## 题3：剑指Offer（二十八）-- 数组中次数出现超过一半的数字

#### 题目描述

数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

#### 思路与解析

这里主要使用了多数投票法，先取第一个数字，出现次数是1，遍历后面的数字，如果相同则加1，如果不同则减1，结果如果为0，则把当前的数字更新，而且次数更新为1。

直到最后，则可以获取到出现次数最多的数字，再次遍历数组，统计该数字出现的次数，如果次数大于长度的一半，则说明是该数字。

摩尔投票法找到数组主要元素 [03_find_multi_ele.c](https://github.com/carloscn/structstudy/blob/master/algo/array/src/03_find_multi_ele.c)

## 题4：数组中的重复数字（可以修改数组）

https://github.com/carloscn/structstudy/blob/master/algo/array/src/05_find_repeat_value_in_array.c

在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中第一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。

我拿到这个题的时候没有任何的思路，按照暴力的方法只能进行o(n^2)的遍历。

### 方法一：暴力破解法

### 方法二：元素和索引置换法a[i] == a[a[i]]

参考：https://blog.csdn.net/csdn_wangchen/article/details/107124902

![在这里插入图片描述](https://raw.githubusercontent.com/carloscn/images/main/typora20200704152334738.gif)

## 题5：数组中的重复数字（不可以修改数组）

上一题的数组修改了数组，这个题目要求不修改数组，可以使用二分查找法对重复数组进行运算。

https://github.com/carloscn/structstudy/blob/master/algo/array/src/06_find_repeat_values_in_array.c

![image-20220818204342287](https://raw.githubusercontent.com/carloscn/images/main/typoraimage-20220818204342287.png)

此题有个思想就是，366人中必然有重复生日的人。我们把vector模板数组 {1,2,3,4,5,6,7,8} 带入到二分后的数组，查个数即可。这个过程是：

*   把数组一分为二分为左数组和右数组
*   统计左数组中 模板数组{1,2,3,4} 在整个数组出现的个数，1出现了1次，2出现1次，3出现了2次，4出现1次，所以共5次；
*   4<5，因此左数组必然有重复，继续二分左数组：{2, 3} {5, 4}
*   继续从左数组开始判定 模板数组{1, 2} ：1出现了1次，2出现1次，所以子数组元素共2次。
*    2=2，因此左数组没有重复，计算右数组 模板数组{3, 4} , 3出现了2次，4出现了1次所以共三次。
*   出现次数3次大于数组个数，则右数组有重复。
*   继续从右数组开始判定 模板数组 {3} {4}
*   从左数组开始判定，3出现了2次，大于元素个数，因此重复数字就是3。

## 题6：在二维数组中查找数字

![image-20220819171735395](https://raw.githubusercontent.com/carloscn/images/main/typoraimage-20220819171735395.png)

### 方法一： 二维数组线性化

很容易想到，二维数组在内存中排列也是线性化的，使用线性查找法找到想要的元素，这个复杂度为O(n*m)。

### 方法二：技巧性

数组无论是x方向，还是y方向都是递增的，因此可以这样，从某个边角开始，和要查的元素进行对比，（这里以右上角的4为例子）如果小于这个元素，向左移动，然后和左面的值查找，如果大于这个元素，向下移动，直到有一方到了边界为止。

这里面有几个知识点：

*   二维数组作为参数传递https://www.jianshu.com/p/d7f2afe08f41
    *   注意二维数组`a[][p]`p的位置不能空；或者作为参数`int (*a)[]`也可以

## 题7：替换字符串空格

`We are happy.` -> `We%20are%20happy.`

### 方法一：普通方法

*   创建一个能够容纳最新字符串的新数组
*   开始从第一个字节遍历。
*   如果不是空格直接复制过去
*   如果是空格把`%20`三个字符复制过去新的数组。

### 方法二：双指针同步复制方法

如果这个问题不允许修改原始的数组，最大的考量就是不要有内存覆盖，因此必须有数组扩充，我们需要知道扩充后的数组是多大的（要统计空格数目）。其次，如果我们从前面每次都移动数据，后面的信息就会被覆盖，我们还要花精力去保护数据，所以从后面移动是一个很好的选择。

这里利用C语言的指针方便的特性，定义双指针，p2和p1同步移动复制，完成字符串的搬移，然后切换指针的值。

![image-20220819173828152](https://raw.githubusercontent.com/carloscn/images/main/typoraimage-20220819173828152.png)
