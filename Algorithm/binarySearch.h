#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

#include "qsort.h"

//https://blog.csdn.net/program_developer/article/details/80348077

// binary search in ordered array - ��������е��۰���ҵ�ʱ��Ч����o(logN)��

// none-recursive
int binary_search_none_recursive(const std::vector<int>& vec, int key)
{
	int low = 0;
	int high = vec.size() - 1;
	for (;;)
	{
		int mid = (low + high) / 2;
		if (vec[mid] == key)
		{
			return mid;
		}
		else if (vec[mid] > key)
		{
			high = mid - 1;
		}
		else if (vec[mid] < key)
		{
			low = mid + 1;
		}
	}
}

int binary_search_recursive(const std::vector<int>& vec, int key, int low, int high)
{
	int mid = (low + high) / 2;
	if (vec[mid] == key)
		return mid;
	else if (vec[mid] > key)
		return binary_search_recursive(vec, key, low, mid - 1);
	else if (vec[mid] < key)
		return binary_search_recursive(vec, key, mid + 1, high);
}


void binary_search_ordered()
{
	std::vector<int> v{1, 4, 8, 2, 0, 7, 3, 15, 12, 17, 18, 3, 4, 3, 2};
	std::sort(v.begin(), v.end());
	for (auto i : v)
		std::cout << i << " ";
	std::cout << std::endl;

	int key = 18;
	int idx1 = binary_search_recursive(v, key, 0, v.size() - 1);
	int idx2 = binary_search_none_recursive(v, key);

	std::cout << "binary search recursive the idx of key: " << key << " is : " << idx1 << std::endl;
	std::cout << "binary search none recursive the idx of key: " << key << " is : " << idx2 << std::endl;
}

//----------------------------------------------------------------------------------------------------------

//�����������н����۰���ҡ�
//��ǰ���˽���۰������������֮һ���ǣ����������ʹ�á���ô�������۰���һ������������������еĲ��ң�����ʱ�临�Ӷ���O(NlongN)��

//����˼�룺
//��Ͽ��ŵ�˼�룬��ÿ��ѡ��һ���ؼ��֣��Ƚ�����������������ұߣ�����С������������ߣ�Ȼ��Ƚ�����Ҫ���ҵ����Ĺ�ϵ����ѡ���´ε��������䡣

//ע�⣺��󣬲��ҽ���֮�����ǵ������Ѿ��Ǵ�������������ˣ�����ԭ�������顣
//����������ʹ�ö��ֲ����㷨��ʱ�临�Ӷ���O(NlogN)��

int binary_serach_unordered_impl(std::vector<int>& vec, int low, int high, int key)
{
	if (low < high)
	{
		int mid = partion(&vec[0], low, high);
		if (vec[mid] == key)
			return mid;
		else if (vec[mid] < key)
		{
			return binary_serach_unordered_impl(vec, mid + 1, high, key);
		}
		else if (vec[mid] > key)
		{
			return binary_serach_unordered_impl(vec, low, mid - 1, key);
		}
	}
}

void binary_search_unordered()
{
	std::vector<int> v{ 1, 4, 8, 2, 0, 7, 3, 15, 12, 17, 18, 3, 4, 3, 2 };
	for (auto i : v)
		std::cout << i << " ";
	std::cout << std::endl;

	int key = 12;
	int idx = binary_serach_unordered_impl(v, 0, v.size() - 1, key);
	
	std::cout << "after unordered binary search, the array is: " << std::endl;
	for (auto i : v)
		std::cout << i << " ";
	std::cout << std::endl;

	std::cout << "unordered binary search recursive the idx of key: " << key << " is : " << idx << std::endl;
}


//----------------------------------------------------------------------------------------------------------

//���ַ������������е�KС����
//���ַ��������������в��ң�Ҳ��ʵ���ö��ַ��������������ҵ�kС������ʱ�临�Ӷ���O(NlongN)��
//���ϱߴ�����һ��С�ĸĶ�����ʵ�֡�

// ������kС����
int unordered_search_select_k_small_impl(std::vector<int>& vec, int low, int high, int k)
{
	if (low < high)
	{
		int partition = partion(&vec[0], low, high);
		int cntleft = partition - low + 1;
		if (cntleft == k)
			return vec[partition];
		else if (cntleft > k)
		{
			return unordered_search_select_k_small_impl(vec, low,  partition - 1, k);
		}
		else if (cntleft < k)
		{
			return unordered_search_select_k_small_impl(vec, partition + 1, high, k - cntleft);
		}
	}
	else
		return vec[low];
}

// ������k�����
int unordered_search_select_k_big_impl(std::vector<int>& vec, int low, int high, int k)
{
	if (low < high)
	{
		int partition = partion(&vec[0], low, high);
		int cntRht = high - partition + 1;

		if (cntRht == k)
			return vec[partition];

		else if (cntRht > k)
		{
			return unordered_search_select_k_big_impl(vec, partition + 1, high, k);
		}
		else if (cntRht < k)
		{
			return unordered_search_select_k_big_impl(vec, low, partition - 1, k - cntRht);
		}
	}
	else
		return vec[low];
}

void select_k()
{
	std::vector<int> v{ 1, 4, 8, 2, 0, 7, 3, 15, 12, 17, 18, 3, 4, 3, 2 };
	for (auto i : v)
		std::cout << i << " ";
	std::cout << std::endl;

	int k = 5;
	std::cout << "�� " << k << " small is: " << unordered_search_select_k_small_impl(v, 0,v.size() - 1, k) << std::endl;
	std::cout << "�� " << k << " big is: " << unordered_search_select_k_big_impl(v, 0, v.size() - 1, k) << std::endl;

}