#ifndef BFS_DFS_H
#define BFS_DFS_H

#include <vector>
#include <deque>
#include <map>
#include <cassert>
#include "vertex.h"

class BfsDfs
{
public:

	BfsDfs(int width, int height, const std::vector<vertex>& vec, int target):width_(width), height_(height), target_(target), x_(-1), y_(-1)
	{
		vec_.assign(vec.begin(), vec.end());
	}

	bool bfs(/*int width, int height, const std::vector<vertex>& vec, std::vector<std::pair<int, int> >& path, int target, int& x, int& y*/)
	{
		std::deque<vertex> vertexTmp;
		std::vector<int> mark;
		mark.reserve(width_ * height_);
		mark.assign(width_ * height_, 0);

		vertexTmp.push_back(vec_[0]);

		while (!vertexTmp.empty())
		{
			vertex temp = vertexTmp.front();
			vertexTmp.pop_front();
			path_.push_back(std::make_pair(temp.x, temp.y));
			if (temp.val == target_)
			{
				x_ = temp.x;
				y_ = temp.y;
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

				if (leftX >=0 && leftX < width_ && leftY >= 0 && leftY < height_ && mark[leftY * width_ + leftX] == 0)
				{
					vertexTmp.push_back(vec_[leftY * width_ + leftX]);
					mark[leftY * width_ + leftX] = 1;
				}

				if (rightX >=0 && rightX < width_ && rightY >= 0 && rightY < height_ && mark[rightY * width_ + rightX] == 0)
				{
					vertexTmp.push_back(vec_[rightY * width_ + rightX]);
					mark[rightY * width_ + rightX] = 1;
				}

				if (upX >=0 && upX < width_ && upY >= 0 && upY < height_ && mark[upY * width_ + upX] == 0)
				{
					vertexTmp.push_back(vec_[upY * width_ + upX]);
					mark[upY * width_ + upX] = 1;
				}

				if (downX >=0 && downX < width_ && downY >= 0 && downY <height_ && mark[downY * width_ + downX] == 0)
				{
					vertexTmp.push_back(vec_[downY * width_ + downX]);
					mark[downY * width_ + downX] = 1;
				}
			}
		}

		return false;
	}

	void dfs(const vertex& v, std::vector<int>& mark, bool& found)
	{
		if (found)
			return;

		assert(v.x >=0 && v.x < width_);
		assert(v.y >=0 && v.y < height_);

		path_.push_back(std::make_pair(v.x, v.y));
		if (vec_[v.y * width_ + v.x].val == target_)
		{
			x_ = v.x;
			y_ = v.y;
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
		if (leftx >=0 && leftx < width_ && lefty >=0 && lefty < height_ && mark[lefty * width_ + leftx] == 0)
		{
			vertexTmp.push_back(vec_[lefty * width_ + leftx]);
			mark[lefty * width_ + leftx] = 1;
		}

		if (rightx >=0 && rightx < width_ && righty >=0 && righty < height_ && mark[righty * width_ + rightx] == 0)
		{
			vertexTmp.push_back(vec_[righty * width_ + rightx]);
			mark[righty * width_ + rightx] = 1;
		}

		if (upx >=0 && upx < width_ && upy >=0 && upy < height_ && mark[upy * width_ + upx] == 0)
		{
			vertexTmp.push_back(vec_[upy * width_ + upx]);
			mark[upy * width_ + upx] = 1;
		}

		if (downx >=0 && downx < width_ && downy >=0 && downy < height_ && mark[downy * width_ + downx] == 0)
		{
			vertexTmp.push_back(vec_[downy * width_ + downx]);
			mark[downy * width_ + downx] = 1;
		}

		for (size_t i=0; i<vertexTmp.size(); i++)
			dfs(vertexTmp[i], mark, found);
	}

	void print_result()
	{
		
	}

private:
	int width_;
	int height_;
	std::vector<vertex>& vec_;
	std::vector<std::pair<int, int> >& path_;
	int target_;
	int x_;
	int y_;
};

#endif