# 数组相关的题目

本目录包含剑指offer的数组相关题目，可能在数组中会涉及一些算法的思想，包含：

*   数组查找 [01_find_array_element.c](https://github.com/carloscn/structstudy/blob/master/algo/array/src/01_find_array_element.c)
*   冒泡排序 [02_odd_find.c](https://github.com/carloscn/structstudy/blob/master/algo/array/src/02_odd_find.c)
*   摩尔投票法找到数组主要元素 [03_find_multi_ele.c](https://github.com/carloscn/structstudy/blob/master/algo/array/src/03_find_multi_ele.c)

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

## 剑指Offer（十三）--调整数组顺序使奇数位于偶数前面

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

冒泡排序 [02_odd_find.c](https://github.com/carloscn/structstudy/blob/master/algo/array/src/02_odd_find.c)

![image-20220817185517523](https://raw.githubusercontent.com/carloscn/images/main/typoraimage-20220817185517523.png)

## 剑指Offer（二十八）-- 数组中次数出现超过一半的数字

#### 题目描述

数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

#### 思路与解析

这里主要使用了多数投票法，先取第一个数字，出现次数是1，遍历后面的数字，如果相同则加1，如果不同则减1，结果如果为0，则把当前的数字更新，而且次数更新为1。

直到最后，则可以获取到出现次数最多的数字，再次遍历数组，统计该数字出现的次数，如果次数大于长度的一半，则说明是该数字。

摩尔投票法找到数组主要元素 [03_find_multi_ele.c](https://github.com/carloscn/structstudy/blob/master/algo/array/src/03_find_multi_ele.c)