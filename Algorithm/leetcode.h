#pragma once
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution
{
public:
	// �����в�ΪK������  leetcode 532
	int findPairs(vector<int>& nums, int k)
	{
		map<int, int> mp;
		int cnt = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			int cur = nums[i];
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (abs(cur - nums[j]) == k)
				{
					int small = min(cur, nums[j]);
					if (mp.find(small) == mp.end())
					{
						cnt++;
						mp[small] = cur > nums[j] ? cur : nums[j];
					}
				}
			}
		}
		return cnt;
	}

	// �������ô���   https://blog.csdn.net/a786150017/article/details/79689885
	int findTimes(int n)
	{


	}


	// https://blog.csdn.net/duxinyuhi/article/details/53710808
	int findQuestionCnt(int n, const std::vector<int>& vec)
	{


	}

	// ��ȷ��С�����nλ
	std::string divideToN(int dividend, int divisor, int n)
	{
		bool diffSign = ((dividend ^divisor) >> 31);

		std::ostringstream ostreamRet;
		if (diffSign)
			ostreamRet << "-";

		dividend = dividend < 0 ? dividend * (-1) : dividend;
		divisor = divisor < 0 ? divisor * (-1) : divisor;

		int m = dividend;
		for (int i = 0; i < n + 1; i++)
		{
			int v = m / divisor;
			m = m % divisor;
			m *= 10;
			ostreamRet << v;
			if (i == 0)
				ostreamRet << ".";
		}

		return ostreamRet.str();
	}



	// http://group.jobbole.com/23591/
	/*
	�� n ���ַ�����ÿ���ַ��������� A-J �Ĵ�д�ַ����ɡ������㽫ÿ���ַ�ӳ��Ϊһ�� 0-9 �����֣���ͬ�ַ�ӳ��Ϊ��ͬ�����֡�
	����ÿ���ַ����Ϳ��Կ���һ��������Ψһ��Ҫ������Щ���������������������ǵ��ַ���������ǰ���㡣������������ӳ���ַ�����ʹ����Щ�ַ�����ʾ������֮�����
	��������:
	ÿ���������������һ�����ݣ�ÿ�����ݵ�һ��Ϊһ�������� n �� �������� n �У�ÿ��һ�����Ȳ����� 12 �ҽ�������д��ĸ A-J ���ַ����� n ������ 50��
	�����ٴ���һ���ַ������κ��ַ���������ĸ��
	�������:
	���һ��������ʾ�����Ƕ��١�
	��������:
	2
	ABC
	BCA
	�������:
	1875

	��������λ����Ȩ������
	ABC = 100 x 10 x 1
	BCA = 100 x 10 x 1
	A = 101
	B = 110
	C = 11
	����Aȡ9��Bȡ8��Cȡ7
	�ý��1875��
	һ����˵Ȩ����С��ӳ��Ϊ0����Ϊ0��������λ������д�����ʱ����Ҫ���⴦��0��
	*/
	int biggestSum()
	{

	}


	// https://blog.csdn.net/x_iya/article/details/79740854
	// ����������һ�����������б�alist��һ��������T����װ������[1,3,6,4,2,7]������alist��������ӵ���T��Ԫ�ص�list��ÿ����ֻ��һ�Ρ�����T=7��
	// �б���3+4=7��7=7��1+6=7����ĺ�����Ҫ����[[3,4],[7],[1,6]]
	// ���Ӷ� n^2
	std::vector<std::vector<int> > findList_impl1(const std::vector<int>& vec, int sum)
	{
		std::vector<std::vector<int> > retVec;
		std::map<int, int> logMap;

		for (int i = 0; i < vec.size(); i++)
		{
			int cur = vec[i];
			std::vector<int> tempVec;

			if (sum == cur)
			{	
				if (logMap.find(0) == logMap.end())
				{
					tempVec.push_back(cur);
				}
			}

			for (int j=0; j<vec.size(); j++)
			{
				if (j == i) continue;
				if (vec[j] + cur == sum)
				{
					int key = min(cur, vec[j]);
					auto ite = logMap.find(key);
					if (ite == logMap.end())
					{
						tempVec.push_back(cur);
						tempVec.push_back(vec[j]);

						logMap[key] = max(cur, vec[j]);
					}
				}
			}

			if (!tempVec.empty())
				retVec.emplace_back(tempVec);
		}
		return retVec;
	}


	// ���ݷ� + �ݹ�
	std::vector<std::vector<int> > findList_impl2(const std::vector<int>& vec, int sum)
	{

	}

	// ��һ�����޶���ÿ����ֻ����һ�Σ��ڶ��ⲻ�����ơ����ǿ���1+1+1+1+��=7��Ҳ����2+2+3=7����ʵ�͵�һ�ⳬ����ֻҪ��һ������ֵ�ͺ�.
	std::vector<std::vector<int> > findList_impl3(const std::vector<int>& vec, int sum)
	{

	}


	// �������б�ʵ�ֶ��е�push��pop���ܡ�
	//class MyQueue
	//{
	//public:
	//	void push(int a)
	//	{
	//		vecA.push_back(a);
	//	}

	//	void pop()
	//	{
	//		if (vecB.empty())
	//		{
	//			if (!vecA.empty())
	//				vecB.assign(vecA.begin(), vecA.end());
	//			else
	//			{
	//				std::cout << "pop failed - no data" << std::endl;
	//				return;
	//			}
	//		}
	//		
	//		vecB.pop_back();
	//	}

	//private:
	//	std::vector<int> vecA;
	//	std::vector<int> vecB;
	//};

	// �ж�һ���ַ����Ƿ�����һ�����Ӵ�
	const char* strstr_impl(const char* str, const char* sub)
	{
		for (int i = 0; str[i] != '\0'; i++)
		{
			int tem = i;                    //tem���������е���ʼ�ж��±�λ�� 
			int j = 0;
			while (str[i++] == sub[j++])
			{
				if (sub[j] == '\0')
				{
					return &str[tem];
				}
			}
			i = tem;
		}
		return nullptr;
	}

	// ����һ��û���ظ����ֵ����У����������п��ܵ�ȫ���С�
	// https://leetcode-cn.com/problems/permutations/description/
	// https://www.cnblogs.com/huashanqingzhu/p/3569835.html

	void permute_helper(std::vector<int>& a, std::vector<int> flg, int idx, std::vector<int>& anss, int& cnt )
	{
		if (idx == a.size() - 1)
		{
			for (int j = 0; j < a.size(); j++)
			{
				if (flg[j] == 0)
				{
					anss[idx] = a[j];

					for (int k = 0; k < anss.size(); k++)
					{
						std::cout << anss[k] << " ";
					}
					std::cout << endl;
					cnt++;
					return;
				}
			}
		}
		else
		{
			for (int j=0; j<a.size(); j++)
			{
				if (flg[j] == 0)
				{
					anss[idx] = a[j];
					flg[j] = 1;

					permute_helper(a, flg, idx + 1, anss, cnt);

					flg[j] = 0;
				}
			}
		}
	}

	void permute(vector<int>& nums)
	{
		std::vector<int> flag(nums.size(), 0);
		std::vector<int> ans(nums.size(), 0);
		int count = 0;
		permute_helper(nums, flag, 0, ans, count);
		std::cout << count << std::endl;
	}

	/*
	����ôn���б�ÿ���б��в�ȷ����>=0������û�������б��ų��������[3��0��9��11��2��..]��������Ҫÿ���б�����ѡ��һ��Ԫ�أ��ֱ�Ϊa1��a2��.an .
	ʹ������ a1<=a2<=a3<=��.<.an �Ļ�����a1+a2+����������+an��ֵ���
	�Ƚ�������㷨˼�벢��˵�����㷨��ʱ�临�Ӷȣ�Ȼ��д��ʱ�为��ȡ������䣬��n���б��λ���ǹ̶��ģ���һ���б�ѡ������Ԫ�ؾ���a1���ڶ�������n2�����ÿ�����ѡ��һ���б�
	������һ�ֲ�ʹ�����飬�Ҿ��밲�����ȵĻ��ţ�����һ�������׵ķ��������Ǵ�an��ѡ���ģ���an-1��ѡС��an�������ġ��ڹ����п����ж�һ���Ƿ������ǰ�����Ϳ����ˡ�
	*/
	// O��n^2��
	int findMaxSumNList(const std::vector<std::vector<int>>& nums, int n)
	{
		assert(nums.size() == n);

		int sum = 0;
		int previousMax = INT_MAX;
		for (int i = n - 1; i >= 0; i--)
		{
			const std::vector<int>& vec = nums[i];
			if (!vec.empty())
			{
				int maxVal = INT_MIN;
				for (auto i : vec)
				{
					if (i < previousMax)
						maxVal = i > maxVal ? i : maxVal;
				}

				sum += maxVal;
				previousMax = maxVal;
			}
		}

		return sum;
	}

	/*
	�ڶ��⣺��һ����·����·���кܶ��������ĸ߶Ȳ�һ������Ҫͳһ�����������߶�Ϊh����˼���ǣ���h�ߵ���������h����h�͵����߶Ȳ��䡣
	���е����������ܳ���ΪC������ҪʹC>ĳ��ֵ�������(����ΪMM)��ʹh�������ôȷ��h��
	���õĶ��ַ�����ʼmin=0��max=��ߵ�����mid=��min+max��/2����ȷ��һ�����a�������С��ĳ������ʱ�����Ϊ���h������Ҫ�ĸ߶ȡ�
	Ȼ�������� ��������ʮ��-6�η���ʱ�临�Ӷ��Ƕ���
	*/

	float findHeight(const std::vector<float>& vec, float C, float low, float high)
	{
		float h = (low + high) / 2;

		float sum = 0;
		for (auto i : vec)
		{
			if (i > h)
				sum += (i - h);
		}

		if (abs(C - sum) < 0.001f)
		{
			return h;
		}
		else
		{
			if (C > sum)
			{
				return findHeight(vec, C, low, h);
				
			}
			else if (C < sum)
			{
				return findHeight(vec, C, h, high);
			}
		}
	}

	/*
	ѭ�������б�[7��7��8��9��1��2��5��6��7��7]���������ѭ�����ƿ��Ա��һ��������б���������б����Ƿ���ĳ������˵�����˼·��
	�ҵ�һ�������Ǳ������������list[0]�ʹ�ǰ�����������С��list[0]�ʹӺ���ǰ�������������ˡ�
	�ڶ��������Ƕ��ַ������Ҫ���ҵ���aС��list[mid]����ô�����һ����list[:mid]�����Ҫ�鵽��������list[mid],������������������list[0]������ߣ�
	���С�ڣ������ұߡ�
	*/
	int findElem(const std::vector<int>& vec, int n)
	{


	}

	/*
	����һ��n*m�ľ���A��A��ÿ��Ԫ��Aij��16��������
	Ѱ��һ�������Ͻǵ����½ǵ�·����ÿ��ֻ�����һ��������ƶ���ʹ��·������������֮����16�����µĺ�׺0���١�
	����������
	��һ�� n�� m    n>=2, m<=1000
	��������n�У�ÿ��m��16������  0 <= Aij <= 10^9

	���������
	��һ�� ���ٺ�׺0�ĸ�����ʮ���ƣ�
	�ڶ��� ·�����������Ͻǿ�ʼ > ��ʾ���ң�v��ʾ���£�����ɶ��ַ���������ֵ�����С�ķ�����>���ֵ���С��v��

	ʾ����
	3 3
	3 2 8
	c 8 8
	2 a f

	��� 
	1
	>>vv

	˼·��̰���㷨+������ȱ���+����
	
	*/

	int findPath(const std::vector<std::vector<int>>& input, std::vector<std::string>& path)
	{

	}


	/*
	�� n �������� a_1,��,a_n�� �� n ����˳���ų�һ�к�ָ�� m �Σ�ÿһ�εķ�������Ϊ������������ĺͣ��ôηָ�ķ�������Ϊ m �η��������ֵ�������зָ���зָ��������Сֵ�Ƕ��٣�

	����������
	��һ�����θ��������� n, m��
	�ڶ������θ���n �������� a1,...,an

	ʾ����

	����
	5 3
	1 4 2 3 5
	���
	5

	˵��
	�ָ�� 1 4 | 2 3 | 5 ��ʱ�����εķ�����Ϊ 5���õ��ָ��������Сֵ��

	��ע��
	�������е����ݣ��� m <= n <= 100000,0 <= ai

	˼·

	�� n ��������Ϊ n �Σ��ָ������Ϊ n �������������ֵ��
	�� n ��������Ϊ 1 �Σ��ָ������Ϊ n ���������ĺͣ�
	����Ϊ m �Σ���ָ����һ���������ֵ���֮�䡣��˲��ö��ֲ��ң�ÿ��ȡһ��ֵ�����н��л��֣����ܻ��ֳ�
	m �Σ�ʹ��ÿ�εĺͶ�С�������ֵ�������㻮�֣���֮�����㣬ֱ���ҵ�һ����С�����㻮�ֵ�ֵΪֹ��
	*/



	// leetcode 149 ����һ����άƽ�棬ƽ������ n ���㣬������ж��ٸ�����ͬһ��ֱ���ϡ�
	// Definition for a point.
	 struct Point {
	     int x;
	     int y;
	     Point() : x(0), y(0) {}
	     Point(int a, int b) : x(a), y(b) {}
	 };
	
	 struct Slop
	 {
		 std::string slop;
		 int num;

		 Slop() : slop("0.0"), num(0) {}
		 Slop(const std::string& x, int y) : slop(x), num(y) {}
	 };


	 int maxPoints(vector<Point>& points)
	 {
		 if (points.empty()) return 0;

		 int maxnum = 0;
		 for (int i = 0; i < points.size(); i++)
		 {
			 int samenum = 0;
			 Point& p = points[i];
			 std::vector<Slop> tempVec;

			 for (int j = 0; j < points.size(); j++)
			 {
				 Point& q = points[j];

				 std::string s = "888888888.0";
				 if (p.x == q.x && p.y == q.y)
					 samenum++;
				 else if (p.x == q.x && p.y != q.y)
					 s = "999999999.0";
				 else
					 s = divideToN((q.y - p.y), (q.x - p.x), 20);

				 bool found = false;
				 int idx = 0;
				 for (idx = 0; idx < tempVec.size(); idx++)
				 {
					 if (s == tempVec[idx].slop)
					 {
						 found = true;
						 break;
					 }
				 }

				 if (found)
				 {
					 tempVec[idx].num++;
				 }
				 else
				 {
					 if (s == "888888888.0")
						 ;
					 else
						tempVec.emplace_back(Slop(s, 1));
				 }
			 }

			 int tempMax = 0;
			 for (auto sl : tempVec)
			 {
				 if (sl.num > tempMax)
				 {
					 tempMax = sl.num;
				 }
			 }
			 tempMax += samenum;

			 maxnum = maxnum < tempMax ? tempMax : maxnum;

		 }
		 return maxnum;
	 }



	 /*
	 ����һ������n������������nums���ж�nums���Ƿ��������Ԫ��a��b��c��ʹ��a+b+c=0��
	 �ҳ��������������Ҳ��ظ�����Ԫ�顣
	 ���磺nums = {-1��0��1��2��-1��-4}
	 ����Ҫ�����Ԫ�鼯��Ϊ��
	 [-1,0,1]
	 [-1,-1,2]
	 ˼·����ԭ�����������Ȼ��ʼ�������������飬����ע�ⲻ�Ǳ��������һ��ֹͣ�����ǵ������������Ϳ����ˡ�
	 �������ǿ�����������֦�Ż������ǵ�������������ʱ���break����Ϊ��������������ģ������һ��Ҫfix�����������ˣ���ô���������
	 ������������Զ������ֺ�Ϊ0�������Ȼ�����ǻ�Ҫ�����ظ��������Ĵ����������Ǵӵڶ�������ʼ�������ǰ���������Ⱦ���������Ϊ���ǲ������ͬ��
	 ����fix���Ρ����ڱ�������������0��ȥ���fix�������õ�target��Ȼ��ֻ��Ҫ���ҵ�������֮�͵���target���ɡ�
	 ����������ָ��ֱ�ָ��fix����֮��ʼ���������β�����������������֮�����õ���target������2������fix����һ��������С�
	 Ȼ����������ظ����ֵĲ����ˣ�����ָ�붼��Ҫ����ظ����֡��������֮��С��target�������ǽ���ߵ�ָ������һλ��ʹ��ָ������ִ�һЩ��ͬ��������
	 ֮�ʹ���target�������ǽ��ұ��Ǹ�ָ������һλ��ʹ��ָ������ּ�СһЩ��
	 */
	 std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
	 {
		 std::vector<std::vector<int>> res;
		 std::sort(nums.begin(), nums.end());
		 if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
		 for (int k = 0; k < nums.size(); k++)
		 {
			 if (nums[k] > 0) break;
			 if (k > 0 && nums[k] == nums[k - 1]) continue;
			 int target = 0 - nums[k];
			 int i = k + 1;
			 int j = nums.size() - 1;
			 while (i < j)
			 {
				 if (nums[i] + nums[j] == target)
				 {
					 res.push_back({ nums[k], nums[i], nums[j] });
					 i++;
					 while (i < j && nums[i] == nums[i + 1]) i++;
					 while (i < j && nums[j] == nums[j - 1]) j--;
				 }
				 else if (nums[i] + nums[j] < target)
				 {
					 i++;
				 }
				 else
				 {
					 j--;
				 }
			 }
		 }
		 return res;
	 }

};