#pragma once

/*
СT���������һ��������Ϸ
��֪������N���߶Ȼ�����ͬ�����壬СT�տ�ʼ�ڸ߶�Ϊ0�ĵط���ÿ����Ծ����ѡ�����Լ���ǰ�߶Ⱦ���ֵ��С�ڵ���H�����壬��Ծ���󵽴�������Ϊ��ľ���λ�ã�
��СT�������K�ε������������ߣ�������ʱ�̣��߶Ȳ���Ϊ����

����������
��һ���������� N,K,H
����N�У�ÿ��һ������Ti����ʾ��i��������صĸ߶�

���������
һ����������ʾ����������ĸ߶�

����������
����

3 3 2
1
3
6
���
8

˵����

СT��ʼ�ڸ߶�0�ĵط�
��һ����Ծֻ��ѡ��߶�Ϊ1�����壬�����󵽴�߶�Ϊ2�ĵط������㷽ʽ��
�߶�1 = ��ʼ�߶� +������߶� - ��ʼ�߶ȣ�* 2 = 0 +��1 - 0��* 2 = 2
�ڶ�����Ծֻ��ѡ��߶�Ϊ3�����壬������ﵽ�߶�Ϊ4�ĵط������㷽ʽ��
�߶�2 = �߶�1 +������2�߶� - �߶�1��* 2 = 2 +��3 - 2��* 2 = 4
�ڶ�����Ծֻ��ѡ��߶�Ϊ6�����壬������ﵽ�߶�Ϊ8�ĵط������㷽ʽ��
�߶�3 = �߶�2 +������3�߶� - �߶�2��* 2 = 4 +��6 - 4��* 2 = 8


���ߣ�jl0x62
���ӣ�https ://www.nowcoder.com/discuss/70299?type=0&order=0&pos=7&page=1
��Դ��ţ����

A: ��̰���㷨��ⲻ�ԣ���ȷ���㷨����BFS��������ȱ�����

*/

#include <vector>
#include <queue>
#include <utility>

// N�����壬��ԾK�Σ�HΪ����ֵ��С
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
//	typedef pair<int, int> pii;   // first: �߶ȣ� second: ��Ծ����
//	bool vis[100000];
//	int a[100000];
//
//	int n, k, h;
//	scanf_s("%d%d%d", &n, &k, &h);
//	//t��ʾ�߶�
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
//			// ����a��������ʾ�߶ȣ����p.first+i����߶�ֵ���ڣ�����û�����ʹ���p.first + 2 * i��ԭ������Ծ������ԭ���߶�+2i��λ��
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
