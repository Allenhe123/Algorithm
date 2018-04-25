﻿// Algorithm.cpp
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <cassert>


#define MIN_ERROR 0.00000001

// binary search
double mysqrt_bs(int x)
{
	double begin = 1.0;
	double end = double(x)/2.0 + 1;
	for (;;)
	{
		double mid = (begin + end) / 2;
		if (abs(mid * mid - x) <= MIN_ERROR)
			return mid;
		else
		{
			if (mid * mid > x)
				end = mid;
			else
				begin = mid;
		}
	}
}

// newton   http://www.cnblogs.com/AnnieKim/archive/2013/04/18/3028607.html
double mysqrt_newton(int x)   
{  
	if(x <= 0) return 0;

	double res, lastres;
	res = x;
	for (;;)
	{
		lastres = res;
		res = (res + x / res) / 2;
		if (abs(lastres - res) <= MIN_ERROR)
			break;
	}
	return res;  
}

// Carmack write it
float InvSqrt(float x)
{  
	float xhalf = 0.5f * x;
	int i = *(int*)&x;
	i = 0x5f375a86 - (i>>1);
	x = *(float*)&i;
	x = x*(1.5f-xhalf*x*x);   
	x = x*(1.5f-xhalf*x*x);   
	x = x*(1.5f-xhalf*x*x);  

	return 1/x;
}  


/*
BFS()
{
  输入起始点；
  初始化所有顶点标记为未遍历；
  初始化一个队列queue并将起始点放入队列；

  while（queue不为空）
  {

    从队列中删除一个顶点s并标记为已遍历； 
    将s邻接的所有还没遍历的点加入队列；
  }
}
}
*/
struct vertex
{
	int x;
	int y;
	int val;

	vertex(): x(0), y(0), val(0) {}
	vertex(int xi, int yi, int v): x(xi), y(yi), val(v) {}
};


bool bfs(int width, int height, const std::vector<vertex>& vec, std::vector<std::pair<int, int> >& path, int target, int& x, int& y)
{
	std::deque<vertex> vertexTmp;
	std::vector<int> mark;
	mark.reserve(width * height);
	mark.assign(width * height, 0);

	vertexTmp.push_back(vec[0]);

	while (!vertexTmp.empty())
	{
		vertex temp = vertexTmp.front();
		vertexTmp.pop_front();
		path.push_back(std::make_pair(temp.x, temp.y));
		if (temp.val == target)
		{
			x = temp.x;
			y = temp.y;
			return true;
		}
		else
		{
			int leftX = temp.x - 1;
			int leftY = temp.y;
			int rightX = temp.x + 1;
			int rightY = temp.y;
			int upX = temp.x;
			int upY = temp.y - 1;
			int downX = temp.x;
			int downY = temp.y + 1;

			if (leftX >=0 && leftX < width && leftY >= 0 && leftY < height && mark[leftY * width + leftX] == 0)
			{
				vertexTmp.push_back(vec[leftY * width + leftX]);
				mark[leftY * width + leftX] = 1;
			}

			if (rightX >=0 && rightX < width && rightY >= 0 && rightY < height && mark[rightY * width + rightX] == 0)
			{
				vertexTmp.push_back(vec[rightY * width + rightX]);
				mark[rightY * width + rightX] = 1;
			}

			if (upX >=0 && upX < width && upY >= 0 && upY < height && mark[upY * width + upX] == 0)
			{
				vertexTmp.push_back(vec[upY * width + upX]);
				mark[upY * width + upX] = 1;
			}

			if (downX >=0 && downX < width && downY >= 0 && downY <height && mark[downY * width + downX] == 0)
			{
				vertexTmp.push_back(vec[downY * width + downX]);
				mark[downY * width + downX] = 1;
			}
		}
	}

	return false;
}


/*
DFS（顶点v）
{
  标记v为已遍历；
  for（对于每一个邻接v且未标记遍历的点u）
      DFS（u）;
}
*/

void dfs(int width, int height, const vertex& v, const std::vector<vertex>& vec, std::vector<int>& mark, 
	std::vector<std::pair<int, int> >& path, int target, int& x, int& y, bool& found)
{
	if (found)
		return;

	assert(v.x >=0 && v.x < width);
	assert(v.y >=0 && v.y < height);

	path.push_back(std::make_pair(v.x, v.y));
	if (vec[v.y * width + v.x].val == target)
	{
		x = v.x;
		y = v.y;
		found = true;
	}

	int leftx = v.x - 1;
	int lefty = v.y;
	int rightx = v.x + 1;
	int righty = v.y;
	int upx = v.x;
	int upy = v.y - 1;
	int downx = v.x;
	int downy = v.y + 1;

	std::vector<vertex> vertexTmp;
	if (leftx >=0 && leftx < width && lefty >=0 && lefty < height && mark[lefty * width + leftx] == 0)
	{
		vertexTmp.push_back(vec[lefty * width + leftx]);
		mark[lefty * width + leftx] = 1;
	}

	if (rightx >=0 && rightx < width && righty >=0 && righty < height && mark[righty * width + rightx] == 0)
	{
		vertexTmp.push_back(vec[righty * width + rightx]);
		mark[righty * width + rightx] = 1;
	}

	if (upx >=0 && upx < width && upy >=0 && upy < height && mark[upy * width + upx] == 0)
	{
		vertexTmp.push_back(vec[upy * width + upx]);
		mark[upy * width + upx] = 1;
	}

	if (downx >=0 && downx < width && downy >=0 && downy < height && mark[downy * width + downx] == 0)
	{
		vertexTmp.push_back(vec[downy * width + downx]);
		mark[downy * width + downx] = 1;
	}

	for (size_t i=0; i<vertexTmp.size(); i++)
		dfs(width, height, vertexTmp[i], vec, mark, path, target, x, y, found);
}


int _tmain(int argc, _TCHAR* argv[])
{
	// test sqrt
	double ret = mysqrt_bs(5);
	std::cout<<ret<<std::endl;

	double ret2 = mysqrt_newton(5);
	std::cout<<ret2<<std::endl;

	float ret3 = InvSqrt(5);
	std::cout<<ret3<<std::endl;


	// test bfs & dfs
	int w = 10;
	int h = 10;
	int target = 99;
	std::vector<vertex> vec;
	vec.resize(w * h);
	for (int i=0; i<h; i++)
	{
		for (int j=0; j<w; j++)
		{
			vec[w * i + j] = vertex(j, i, 0);
			if (w * i + j == 66)
				vec[w * i + j] = vertex(j, i, target);
		}
	}

	for (size_t i=0; i<vec.size(); i++)
	{
		std::cout<<vec[i].val<<" ";
		if ((i + 1) % 10 == 0)
			std::cout<<std::endl;
	}

	int x = 0 ;
	int y = 0;
	std::vector<std::pair<int, int> > path;
	bool retbfs = bfs(w, h, vec, path, target, x, y);
	if (retbfs)
	{
		std::cout<<"bfs successful, steps:"<<path.size()<<", path:"<<std::endl;
		for (size_t i=0; i<path.size(); i++)
		{
			std::cout<<"("<<path[i].first<<" , "<<path[i].second<<")" <<" --> "<<std::endl;
		}
	}
	else
	{
		std::cout<<"bfs failed!"<<std::endl;
	}

	std::vector<int> mark;
	path.clear();
	mark.reserve(w * h);
	mark.assign(w * h, 0);

	mark[0] = 1;
	bool found = false;
	dfs(w, h, vec[0], vec, mark, path, target, x, y, found);

	if (found)
	{
		std::cout<<"dfs successful, steps:"<<path.size()<<" path:"<<std::endl;
	}
	else
	{
		std::cout<<"dfs failed!, steps:"<<path.size()<<std::endl;
	}
	for (size_t i=0; i<path.size(); i++)
	{
		std::cout<<"("<<path[i].first<<" , "<<path[i].second<<")" <<" --> "<<std::endl;
	}

	system("pause");
	return 0;
}
