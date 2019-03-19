#pragma once

/*
小T最近迷上了一款跳板游戏
已知空中有N个高度互不相同的跳板，小T刚开始在高度为0的地方，每次跳跃可以选择与自己当前高度绝对值差小于等于H的挑板，跳跃过后到达以跳板为轴的镜像位置，
问小T在最多条K次的情况下能跳多高？（任意时刻，高度不能为负）

输入描述：
第一行三个整数 N,K,H
以下N行，每行一个整数Ti，表示第i个跳板离地的高度

输出描述：
一个整数，表示最高能跳到的高度

输入样例：
输入

3 3 2
1
3
6
输出
8

说明：

小T初始在高度0的地方
第一次跳跃只能选择高度为1的跳板，结束后到达高度为2的地方，计算方式：
高度1 = 初始高度 +（跳板高度 - 初始高度）* 2 = 0 +（1 - 0）* 2 = 2
第二次跳跃只能选择高度为3的跳板，结束后达到高度为4的地方，计算方式：
高度2 = 高度1 +（跳板2高度 - 高度1）* 2 = 2 +（3 - 2）* 2 = 4
第二次跳跃只能选择高度为6的跳板，结束后达到高度为8的地方，计算方式：
高度3 = 高度2 +（跳板3高度 - 高度2）* 2 = 4 +（6 - 4）* 2 = 8


作者：jl0x62
链接：https ://www.nowcoder.com/discuss/70299?type=0&order=0&pos=7&page=1
来源：牛客网

A: 用贪心算法求解不对，正确的算法是用BFS（广度优先遍历）

*/

#include <vector>
#include <queue>
#include <utility>

// N个跳板，跳跃K次，H为绝对值大小
int jump(int n, int k, int h, const std::vector<int>& heights)
{
	if (n != heights.size())  return -1;

	std::vector<bool> mask(100000, false);

	std::queue<std::pair<int, int>> q;  //  current height - current steps
	q.push({0, 0});
	int maxH = 0;

	while (!q.empty())
	{
		std::pair<int, int>& p = q.front();
		q.pop();

		if (p.second > k) break;

		maxH = max(maxH, p.first);

		for (size_t i = 0; i < n; i++)
		{
			if (!mask[i] && heights[i] - p.first <= h)
			{
				q.push({p.first + 2 * (heights[i] - p.first), p.second + 1 });
				mask[i] = true;
			}
		}
	}

	return maxH;
}


//void jump()
//{
//	typedef pair<int, int> pii;   // first: 高度， second: 跳跃次数
//	bool vis[100000];
//	int a[100000];
//
//	int n, k, h;
//	scanf_s("%d%d%d", &n, &k, &h);
//	//t表示高度
//	for (int i = 0; i < n; ++i)
//	{
//		int t;
//		scanf_s("%d", &t);
//		a[t] = 1;
//	}
//
//	queue<pii> q;
//	q.push({ 0, 0 });
//	int ans = 0;
//
//	// BFS
//	while (!q.empty())
//	{
//		pii p = q.front(); q.pop();
//		if (p.second > k) break;
//
//		ans = max(ans, p.first);
//
//		for (int i = 1; i <= h; ++i)
//		{
//			// 数组a的索引表示高度，如果p.first+i这个高度值存在，并且没被访问过。p.first + 2 * i的原因是跳跃后跳到原来高度+2i的位置
//			if (a[p.first + i] && !vis[p.first + 2 * i])
//			{
//				vis[p.first + 2 * i] = true;
//				q.push(make_pair(p.first + 2 * i,  p.second + 1));
//			}
//
//			if (p.first - 2 * i > 0 && a[p.first - i] && !vis[p.first - 2 * i])
//			{
//				vis[p.first - 2 * i] = true;
//				q.push(make_pair(p.first - 2 * i, p.second + 1));
//			}
//		}
//	}
//	printf("%d\n", ans);
//}
