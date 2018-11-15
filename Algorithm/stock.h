#pragma once

//题目： Best Time to Buy and Sell Stock II
//
//假设有一个数组，它的第 i 个元素是一个给定的股票在第 i 天的价格。
//
//设计一个算法来找到最大的利润。你可以完成尽可能多的交易（多次买卖股票）。然而，你不能同时参与多个交易（你必须在再次购买前出售股票）。

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