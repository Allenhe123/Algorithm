#pragma once

#include <random>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <stack>

namespace BYTEDANCE
{
	// 题目：给定一个整形数组，数组是无重复随机无序的，要求打印出所有元素左边第一个大于该元素的值。(左边第一个应该是距离这个值最近的那个值)
	//https://blog.csdn.net/qq_30578131/article/details/80740614
	// 用单调栈来求解

	void shuffle(std::vector<int>& vec, int size)
	{
		srand(time(NULL));

		std::set<int> st;

		for (int i = 0; i < size; i++)
		{
			while (1)
			{
				int temp = rand() % 1024;
				auto ite = st.find(temp);
				if (ite == st.end())
				{
					vec.emplace_back(temp);
					break;
				}
			}
		}
	}

	void bytedance1_normal()
	{
		std::vector<int> v;
		shuffle(v, 10);

		for (auto& i : v)
			std::cout << i << " ";
		std::cout << std::endl;

		for (int i = 0; i < v.size(); i++)
		{
			int val = v[i];
			bool found = false;
			int foundVal = 0;
			std::cout << "current: " << val;
			for (int j = 0; j < i; j++)
			{
				if (v[j] > val)
				{
					found = true;
					foundVal = v[j];
				}
			}

			if (!found)
				std::cout << " can not found a num bigger than current on its left side." << std::endl;
			else
				std::cout << " the first bigger value on left is: " << foundVal << std::endl;
		}
	}


	void bytedance1_priority_stack()
	{
		std::vector<int> v;
		shuffle(v, 10);

		for (auto& i : v)
			std::cout << i << " ";
		std::cout << std::endl;

		std::stack<int> s;

		for (int i = 0; i < v.size(); i++)
		{
			int dest = v[i];

			if (!s.empty() && s.top() > dest)
			{
				std::cout << "current value: " << dest << ", the first bigger value on left is: " << s.top() << std::endl;
			}
			else
			{
				while (!s.empty() && s.top() <= dest)
				{
					s.pop();
				}
				if (!s.empty())
					std::cout << "current value: " << dest << ", the first bigger value on left is: " << s.top() << std::endl;
				else
					std::cout << "current value: " << dest << " can not found a num bigger than current on its left side." << std::endl;
			}

			s.push(dest);
		}
	}
	
	/// 验证一个字符串是否为合法的ipv4地址
	std::vector<std::string> split(const std::string& s, char delimiter)
	{
		std::vector<std::string> tokens;
		std::string token;
		std::istringstream tokenStream(s);
		while (std::getline(tokenStream, token, delimiter))
		{
			tokens.push_back(token);
		}
		return tokens;
	}

	bool isValidIpv4(std::string& ipv4)
	{
		std::vector<std::string> res = split(ipv4, '.');
		if (res.size() != 4) return false;
		for (auto& s : res)
		{
			int val = std::atoi(s.c_str());
			if (val < 0 || val > 255) return false;
		}
		return true;
	}

	/// 给出两个有序数组，其中A数组的长度为另外B数组的两倍，并且有效数字个数都是B数组大小，合并两个数组，要求：时间复杂度为O（n），空间复杂度为O（1）


	/// 如何判断一个链表是否有环

	/// 如何判断一个环的入口

	///	如何用两个栈模拟一个队列

	/// 一个链表，如何进行每两个交换一次的操作

	/// my name is Z X变成Z X is name my

	/// 用两个队列模仿一个栈

	/// 写冒泡排序（写了三个版本）

	/// 封装一个字符串逆序的API


	/// 反转链表

	/// 三种方式遍历二叉树

	/// 手写代理模式

	/// 两个有序数组，求第K大的数

	/// 合并两个有序数组

	/// 二叉树的反转

	/// 实现一个LUR Cache，包含读、写两个操作


	/// 设计一个算法求圆周率

	/// 只能遍历一次文本，需要找出多个关键字的次数，位置

	/// 找出一个32位数二进制表示法中1的个数（需要达到最优解）


	/// 数羊，给定一个初始数N，第一次数的数为N，第二次为2N，依次类推，直到kN，那么求当0-9的数全部都出现的时候的k值
}
