#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

#include "qsort.h"

//https://blog.csdn.net/program_developer/article/details/80348077

// binary search in ordered array - 在有序表中的折半查找的时间效率是o(logN)。

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

//在无序数组中进行折半查找。
//以前我了解的折半查找适用条件之一就是：在有序表中使用。那么，现在折半查找还可以用在无序数组中的查找，查找时间复杂度是O(NlongN)。

//基本思想：
//结合快排的思想，即每次选择一个关键字，先将比它大的数放在其右边，比它小的数放在其左边，然后比较它和要查找的数的关系，并选择下次迭代的区间。

//注意：最后，查找结束之后我们的数组已经是大致有序的数组了，不是原来的数组。
//无序数组中使用二分查找算法的时间复杂度是O(NlogN)。

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

//二分法找无序数组中第K小的数
//二分法能在无序数组中查找，也能实现用二分法在无序数组中找第k小的数。时间复杂度是O(NlongN)。
//对上边代码做一点小的改动即可实现。

// 搜索第k小的数
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

// 搜索第k大的数
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
	std::cout << "第 " << k << " small is: " << unordered_search_select_k_small_impl(v, 0,v.size() - 1, k) << std::endl;
	std::cout << "第 " << k << " big is: " << unordered_search_select_k_big_impl(v, 0, v.size() - 1, k) << std::endl;

}