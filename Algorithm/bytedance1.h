#pragma once

// 题目：给定一个整形数组，数组是无重复随机无序的，要求打印出所有元素左边第一个大于该元素的值。(左边第一个应该是距离这个值最近的那个值)

//https://blog.csdn.net/qq_30578131/article/details/80740614
// 用单调栈来求解


#include <random>
#include <ctime>
#include <iostream>
#include <vector>
#include <set>
#include <stack>

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
			std::cout << " the first bigger value on left is: "<< foundVal << std::endl;
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
				std::cout << "current value: " << dest<< " can not found a num bigger than current on its left side." << std::endl;
		}

		s.push(dest);
	}
}
