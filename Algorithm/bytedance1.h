#pragma once

// ��Ŀ������һ���������飬���������ظ��������ģ�Ҫ���ӡ������Ԫ����ߵ�һ�����ڸ�Ԫ�ص�ֵ��(��ߵ�һ��Ӧ���Ǿ������ֵ������Ǹ�ֵ)

//https://blog.csdn.net/qq_30578131/article/details/80740614
// �õ���ջ�����


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
