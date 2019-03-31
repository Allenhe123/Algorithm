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
	// ��Ŀ������һ���������飬���������ظ��������ģ�Ҫ���ӡ������Ԫ����ߵ�һ�����ڸ�Ԫ�ص�ֵ��(��ߵ�һ��Ӧ���Ǿ������ֵ������Ǹ�ֵ)
	//https://blog.csdn.net/qq_30578131/article/details/80740614
	// �õ���ջ�����

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
	
	/// ��֤һ���ַ����Ƿ�Ϊ�Ϸ���ipv4��ַ
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

	/// ���������������飬����A����ĳ���Ϊ����B�����������������Ч���ָ�������B�����С���ϲ��������飬Ҫ��ʱ�临�Ӷ�ΪO��n�����ռ临�Ӷ�ΪO��1��


	/// ����ж�һ�������Ƿ��л�

	/// ����ж�һ���������

	///	���������ջģ��һ������

	/// һ��������ν���ÿ��������һ�εĲ���

	/// my name is Z X���Z X is name my

	/// ����������ģ��һ��ջ

	/// дð������д�������汾��

	/// ��װһ���ַ��������API


	/// ��ת����

	/// ���ַ�ʽ����������

	/// ��д����ģʽ

	/// �����������飬���K�����

	/// �ϲ�������������

	/// �������ķ�ת

	/// ʵ��һ��LUR Cache����������д��������


	/// ���һ���㷨��Բ����

	/// ֻ�ܱ���һ���ı�����Ҫ�ҳ�����ؼ��ֵĴ�����λ��

	/// �ҳ�һ��32λ�������Ʊ�ʾ����1�ĸ�������Ҫ�ﵽ���Ž⣩


	/// ���򣬸���һ����ʼ��N����һ��������ΪN���ڶ���Ϊ2N���������ƣ�ֱ��kN����ô��0-9����ȫ�������ֵ�ʱ���kֵ
}
