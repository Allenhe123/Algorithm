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
#include "huawei.h"


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


	//std::vector<int> v{ 3, 10, 81, 0 };
	//for (auto i : v)
	//{
	//	std::cout << func1(i) << std::endl;
	//}

	//std::vector<int> v{1,2,3,3,4,5,2,6,90,56,78,56,4,5,6};
	//unique_sort(v);
	//for (auto i : v)
	//{
	//	std::cout << i << std::endl;
	//}

	std::string str = transfer("0x12345ff");
	std::cout << str << std::endl;

	system("pause");
	return 0;
}
