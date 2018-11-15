// Algorithm.cpp
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <cassert>
#include "kmeans.h"
#include "bfs_dfs.h"
#include "mysqrt.h"
#include "qsort.h"
#include "topk.h"
#include "heap.h"
#include "bytedance1.h"
#include "stock.h"
#include "binarySearch.h"
#include "bytedance2.h"
#include "leetcode.h"
#include "LRU.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//// test sqrt
	//double ret = mysqrt_bs(5);
	//std::cout<<ret<<std::endl;

	//double ret2 = mysqrt_newton(5);
	//std::cout<<ret2<<std::endl;

	//float ret3 = InvSqrt(5);
	//std::cout<<ret3<<std::endl;


	//// test bfs & dfs
	//int w = 10;
	//int h = 10;
	//int target = 99;
	//std::vector<vertex> vec;
	//vec.resize(w * h);
	//for (int i=0; i<h; i++)
	//{
	//	for (int j=0; j<w; j++)
	//	{
	//		vec[w * i + j] = vertex(j, i, 0);
	//		if (w * i + j == 66)
	//			vec[w * i + j] = vertex(j, i, target);
	//	}
	//}

	//for (size_t i=0; i<vec.size(); i++)
	//{
	//	std::cout<<vec[i].val<<" ";
	//	if ((i + 1) % 10 == 0)
	//		std::cout<<std::endl;
	//}

	//int x = 0 ;
	//int y = 0;
	//std::vector<std::pair<int, int> > path;
	//bool retbfs = bfs(w, h, vec, path, target, x, y);
	//if (retbfs)
	//{
	//	std::cout<<"bfs successful, steps:"<<path.size()<<", path:"<<std::endl;
	//	for (size_t i=0; i<path.size(); i++)
	//	{
	//		std::cout<<"("<<path[i].first<<" , "<<path[i].second<<")" <<" --> "<<std::endl;
	//	}
	//}
	//else
	//{
	//	std::cout<<"bfs failed!"<<std::endl;
	//}

	//std::vector<int> mark;
	//path.clear();
	//mark.reserve(w * h);
	//mark.assign(w * h, 0);

	//mark[0] = 1;
	//bool found = false;
	//dfs(w, h, vec[0], vec, mark, path, target, x, y, found);

	//if (found)
	//{
	//	std::cout<<"dfs successful, steps:"<<path.size()<<" path:"<<std::endl;
	//}
	//else
	//{
	//	std::cout<<"dfs failed!, steps:"<<path.size()<<std::endl;
	//}
	//for (size_t i=0; i<path.size(); i++)
	//{
	//	std::cout<<"("<<path[i].first<<" , "<<path[i].second<<")" <<" --> "<<std::endl;
	//}

	//// testing k-means
	//Kmeans km(6, 256);
	//km.run_k_means();

	//int a[10] = {5, 6, 0, 9, 7, 4, 1, 6, 3, 4};
	//quickSort(a, 0, 9);
	//for (int i=0; i<10; i++)
	//{
	//	std::cout << a[i] << " ";
	//}
	//std::cout << std::endl;

	//heap();

	//int a[10] = { 5, 6, 0, 9, 7, 4, 1, 6, 3, 4 };
	//int k = 7;
	//BFPTR(a, 0, 9, k);
	//for (int i = 0; i < 10; i++)
	//{
	//	std::cout << a[i] << " ";
	//}
	//std::cout << std::endl;

	//int a = 0xFFFFFFFFUL;
	//std::cout << a << std::endl;

	//char* p = new char[0];
	//std::cout << p << std::endl;
	//std::cout << *p << std::endl;

	//unsigned int a = 10;
	//unsigned int b = 20;
	//int c = a - b;
	//std::cout << c << std::endl;
	

	//bytedance1_normal();
	//bytedance1_priority_stack();

	//int cnt = 0;
	//int x = 1113412145;
	//while (x > 0)
	//{
	//	if (x % 10 == 1)
	//		cnt++;
	//	x = x / 10;
	//}

	//std::cout << cnt << std::endl;
	
	//leetcode_stock();

	//binary_search_ordered();

//binary_search_unordered();

//select_k();

//bytedance2();


Solution sln;

//std::vector<int> vec{ 3, 1, 4, 1, 5 };
//sln.findPairs(vec, 2);

//std::vector<int> vec{ 1,3,6,4,2,7};
//std::vector<std::vector<int>> retV = sln.findList_impl1(vec, 7);
//
//for (auto& v : retV)
//{
//	for (auto i : v)
//	{
//		std::cout << i << " ";
//	}
//	std::cout << endl;
//}

//const char* s = "abcdefg";
//const char* sub = "def";
//
//std::cout << sln.strstr_impl(s, sub) << std::endl;

//std::vector<int> nums{1,2,3};
//sln.permute(nums);

//LRUCache obj(2);
//obj.put(2, 1);
//obj.put(2, 2);
//std::cout << obj.get(1) << std::endl;
//obj.put(3, 3);
//std::cout << obj.get(2) << std::endl;
//obj.put(4, 4);
//std::cout << obj.get(1) << std::endl;
//std::cout << obj.get(3) << std::endl;
//std::cout << obj.get(4) << std::endl;

//std::vector<std::vector<int>> nums;
//std::vector<int> v1{1,2,3,4,5};
//std::vector<int> v2{ 3,4,5,6,9 };
//std::vector<int> v3{ 1,2,3,4,5, 10, 9};
//nums.emplace_back(v1);
//nums.emplace_back(v2);
//nums.emplace_back(v3);
//int sum = sln.findMaxSumNList(nums, 3);
//std::cout << sum << std::endl;

std::vector<float> vec{1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,8.0,9.0,4.0,6.0,8.0,9.0,11.0,23.0,45.0,32.0,2.0,11.0,6.0,7.0,15.0,16.0,6.0,18.0,19.0,11.0,10.0};
float h = sln.findHeight(vec, 30.0, 0.0, 45.0);
std::cout << h << std::endl;

	system("pause");
	return 0;
}
