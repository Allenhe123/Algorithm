#pragma once

#include <unordered_map>
#include <map>
#include <ctime>

// https://leetcode-cn.com/problems/lru-cache/description/
/*
��ƺ�ʵ��һ��  LRU (�������ʹ��) ������ơ���Ӧ��֧�����²����� ��ȡ���� get �� д������ put ��
��ȡ���� get(key) - �����Կ (key) �����ڻ����У����ȡ��Կ��ֵ�����������������򷵻� -1��
д������ put(key, value) - �����Կ�����ڣ���д��������ֵ�������������ﵽ����ʱ����Ӧ����д��������֮ǰɾ���������ʹ�õ�����ֵ���Ӷ�Ϊ�µ�����ֵ�����ռ䡣
����:
���Ƿ������ O(1) ʱ�临�Ӷ�����������ֲ�����

���һ�����������һ��ʱ��û�б����ʵ�����ô�ڽ����������ʵĿ�����Ҳ��С��Ҳ����˵�����޶��Ŀռ��Ѵ�������ʱ��Ӧ�������û�б����ʵ���������̭��
*/

class LRUCache
{
public:
	LRUCache(int capacity) 
	{
		mCapacity = capacity;
	}

	int get(int key) 
	{
		auto ite = mKeyValueMap.find(key);
		if (ite == mKeyValueMap.end())
			return -1;
		else
		{
			auto ite1 = mKeyTimeMap.find(key);
			long oldTime = ite1->second;

			clock_t now = clock();
			auto it = mTimeKeyMap.find(oldTime);
			mTimeKeyMap.erase(it);

			mTimeKeyMap[now] = key;
			mKeyTimeMap[key] = now;

			return ite->second;
		}
	}

	void put(int key, int value) 
	{
		auto ite = mKeyValueMap.find(key);
		if (ite != mKeyValueMap.end())
		{
			mKeyValueMap[key] = value;

			auto ite = mKeyTimeMap.find(key);
			long oldTime = ite->second;
			auto it = mTimeKeyMap.find(oldTime);

			clock_t now = clock();

			mTimeKeyMap.erase(it);
			mTimeKeyMap[now] = key;
			mKeyTimeMap[key] = now;
		}
		else
		{
			if (mKeyValueMap.size() < mCapacity)
			{
				clock_t now = clock();
				mKeyValueMap[key] = value;
				mKeyTimeMap[key] = now;
				mTimeKeyMap[now] = key;
			}
			else
			{
				auto first = mTimeKeyMap.begin();
				int firstKey = first->second;
				mTimeKeyMap.erase(first);

				auto it = mKeyValueMap.find(firstKey);
				mKeyValueMap.erase(it);

				auto ite = mKeyTimeMap.find(firstKey);
				mKeyTimeMap.erase(ite);

				clock_t now = clock();
				mKeyValueMap[key] = value;
				mKeyTimeMap[key] = now;
				mTimeKeyMap[now] = key;
			}
		}
	}

private:
	std::unordered_map<int, long>  mKeyTimeMap;
	std::unordered_map<int, int>   mKeyValueMap;
	std::map<long, int>			   mTimeKeyMap;
	int mCapacity;
};