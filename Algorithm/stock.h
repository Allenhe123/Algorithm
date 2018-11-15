#pragma once

//��Ŀ�� Best Time to Buy and Sell Stock II
//
//������һ�����飬���ĵ� i ��Ԫ����һ�������Ĺ�Ʊ�ڵ� i ��ļ۸�
//
//���һ���㷨���ҵ����������������ɾ����ܶ�Ľ��ף����������Ʊ����Ȼ�����㲻��ͬʱ���������ף���������ٴι���ǰ���۹�Ʊ����

#include <random>
#include <ctime>
#include <iostream>
#include <vector>

void generate(std::vector<int>& vec, int size)
{
	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		vec.emplace_back(rand() % 1024);
	}
}


void leetcode_stock()
{
	int money = 10000;

	std::vector<int> v;
	generate(v, 10);

	for (auto& i : v)
		std::cout << i << " ";
	std::cout << std::endl;

	std::vector<int> profitVec;
	for (int i=0; i<v.size() - 1; i++)
	{
		profitVec.push_back(v[i + 1] - v[i]);
	}

	int profit = 0;
	for (int i=0; i<profitVec.size(); i++)
	{
		if (profitVec[i] > 0)
			profit += profitVec[i] * money / v[i];
	}

	std::cout << "initial money: " << money << std::endl;
	std::cout << "maxProfit: " << profit << std::endl;

}