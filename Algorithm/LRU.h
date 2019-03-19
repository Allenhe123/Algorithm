#pragma once

#include <unordered_map>
#include <map>
#include <ctime>

// https://leetcode-cn.com/problems/lru-cache/description/
/*
设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。
进阶:
你是否可以在 O(1) 时间复杂度内完成这两种操作？

如果一个数据在最近一段时间没有被访问到，那么在将来它被访问的可能性也很小。也就是说，当限定的空间已存满数据时，应当把最久没有被访问到的数据淘汰。
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