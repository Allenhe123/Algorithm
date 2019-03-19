#pragma once

#include <string>
#include <vector>
#include <iostream>

/*
有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，她最多可以换多少瓶汽水喝？”答案是5瓶，方法如下：先用9个空瓶子换3瓶汽水，
喝掉3瓶满的，喝完以后4个空瓶子，用3个再换一瓶，喝掉这瓶满的，这时候剩2个空瓶子。然后你让老板先借给你一瓶汽水，喝掉这瓶满的，喝完以后用3个空瓶子换一瓶满的还给老板。
如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？
输入描述 :
输入文件最多包含10组测试数据，每个数据占一行，仅包含一个正整数n（1 <= n <= 100），表示小张手上的空汽水瓶数。n = 0表示输入结束，你的程序不应当处理这一行。
输出描述 :
对于每组测试数据，输出一行，表示最多可以喝的汽水瓶数。如果一瓶也喝不到，输出0。
输入例子1 :
3
10
81
0
输出例子1 :
	1
	5
	40
*/

int func1(int n)
{
	if (n <= 1) return 0;
	if (n == 2 || n == 3) return 1;

	int x = n / 3;
	int y = n % 3;
	return func1(x + y) + x; // return func1(n - 2) + 1
}


/*
明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了N个1到1000之间的随机整数（N≤1000），对于其中重复的数字，
只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。
请你协助明明完成“去重”与“排序”的工作(同一个测试用例里可能会有多组数据，希望大家能正确处理)。

Input Param
n               输入随机数的个数
inputArray      n个随机整数组成的数组

Return Value
OutputArray    输出处理后的随机整数

A:
1.如果元素被保存在vector中，可先对vector里面的元素排序，然后调用unique函数去重，unique(起始迭代器,终止迭代器)，
返回的是去重以后vector中没有重复元素的下一个位置的迭代器。unique的实现原理大概是判断当前元素是否等于上一个元素，
如果等于就将后一个元素向前覆盖掉当前的元素，所以执行完unique()以后返回的迭代器开始到vector.end()的元素都是没有意义的。
#include <algorithm>
#include <vector>
uning namespace std;
vector<int> v;
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
2. 加入到set容器里再取出来
3. 自己实现 - 位图
*/

void unique_sort(std::vector<int>& v)
{
	int vmax = *std::max_element(v.begin(), v.end());
	std::vector<int> vflag;
	vflag.resize(vmax + 1);
	memset(vflag.data(), 0, sizeof(int) * vflag.size());

	for (auto ite = v.begin(); ite != v.end(); ite++)
	{
		if (vflag[*ite] == 0)
			vflag[*ite] = 1;
		else
		{
			ite = v.erase(ite);
		}
	}

	sort(v.begin(), v.end());
}



/*
写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串。（多组同时输入 ）
*/

std::string transfer(char* pinput)
{
	char* pTmp = pinput;
	if (*pTmp == '0' && (*(pTmp + 1) == 'x' || *(pTmp + 1) == 'X'))
		pTmp = pTmp + 2;

	unsigned long long number  = 0;
	char* plast = pTmp;
	while (*plast != '\0')
	{
		plast++;
	}
	plast--;

	int flag = 0;
	while (plast != pTmp)
	{
		number += pow(16, flag);
		flag++;
		plast--;
	}
	number += pow(16, flag);

	return std::to_string(number);
}
