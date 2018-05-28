#pragma once

#include <queue>
#include <iostream>
#include <functional>  //STL �������㺯���������������
using namespace std;

/*
�󶥶ѣ�С���ѽ��top-k����
���ȶ���(priority_queue)��ʵ���ϣ����ı��ʾ���һ��heap

std::priority_queue<T> pq;
std::priority_queue<T, std::vector<T>, cmp> pq;
����Ĭ����vector, �����������Ƚ���Ҫ��֧��һ���ȽϽṹ��Ĭ����less
��Ȼ�õ���less�ṹ��Ȼ�������еĳ���˳��ȴ��greater���ȳ�������˵���������������ʵ�ܰ�������ʾ����˼�����!cmp�����ȳ���

*/

void heap()
{
	priority_queue<int> pq;
	pq.push(20);
	pq.push(5);
	pq.push(2);
	pq.push(8);
	pq.push(15);
	pq.push(18);
	pq.push(10);

	size_t count = pq.size();
	cout << "count: " << count << endl;
	for (int i = 0; i < count; i++)
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;

	///////////////////////////////////////////////////

	priority_queue<int, vector<int>, greater<int> >ppq;
	ppq.push(20);
	ppq.push(5);
	ppq.push(2);
	ppq.push(8);
	ppq.push(15);
	ppq.push(18);
	ppq.push(10);

	size_t count1 = ppq.size();
	cout << "count: " << count1 << endl;
	for (int i = 0; i < count1; i++)
	{
		cout << ppq.top() << " ";
		ppq.pop();
	}
	cout << endl;

	//////////////////////////////////////////////////////

	struct Node
	{
		int x, y;
		Node(int a = 0, int b = 0) : x(a), y(b) {}
	};

	struct cmp
	{
		bool operator() (Node a, Node b)
		{
			if (a.x == b.x)  return a.y > b.y;
			return a.x > b.x;
		}
	};

	priority_queue<Node, vector<Node>, cmp>pnode;
	for (int i = 0; i < 10; ++i)
		pnode.push(Node(rand(), rand()));

	while (!pnode.empty())
	{
		cout << pnode.top().x << ' ' << pnode.top().y << endl;
		pnode.pop();
	}
}