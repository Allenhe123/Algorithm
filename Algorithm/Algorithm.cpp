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
#include "huawei.h"
#include "mylist.h"
#include "leetcode.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//// test sqrt
	//double ret = mysqrt_bs(5);
	//std::cout<<ret<<std::endl;

	//double ret2 = mysqrt_newton(5);
	//std::cout<<ret2<<std::endl;

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

	//std::cout<<ret3<<std::endl;


	//// test bfs & dfs
	//int w = 10;
	//int h = 10;
	//int target = 99;
	//std::vector<vertex> vec;
	//vec.resize(w * h);
	//for (int i=0; i<h; i++)

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

	//	std::cout<<"bfs successful, steps:"<<path.size()<<", path:"<<std::endl;
	//	for (size_t i=0; i<path.size(); i++)
	//	{
	//		std::cout<<"("<<path[i].first<<" , "<<path[i].second<<")" <<" --> "<<std::endl;
	//	}
	//}

	//	std::cout<<"bfs successful, steps:"<<path.size()<<", path:"<<std::endl;
	//	for (size_t i=0; i<path.size(); i++)


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


	//std::vector<int> v{ 3, 10, 81, 0 };
	//for (auto i : v)
	//{
	//	std::cout << func1(i) << std::endl;
	//}

	//std::vector<int> v{1,2,3,3,4,5,2,6,90,56,78,56,4,5,6};
	//unique_sort(v);
	//for (auto i : v)
	//{
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

	//std::string str = transfer("0x12345ff");
	//std::cout << str << std::endl;

	//MyList lst;
	//lst.init(std::vector<int> {1, 4, 7, 9, 2, 4, 10, 8, 3, 5, 66, 4});
	//std::cout << lst << std::endl;
	//lst.reverse();
	//std::cout << lst << std::endl;
	
	Solution sln;
	std::vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	auto v = sln.threeSum(nums);
	for (auto& vv : v)
	{
		for (auto i : vv)
		{
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}


	system("pause");
	return 0;
}
