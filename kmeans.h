#ifndef K_MEANS_H
#define K_MEANS_H

#include<ctime>
#include<iostream>
#include<cmath>
#include <vector>

#include "vertex.h"

/*
k均值算法的计算过程非常直观：

      1、从D中随机取k个元素，作为k个簇的各自的中心。

      2、分别计算剩下的元素到k个簇中心的相异度，将这些元素分别划归到相异度最低的簇。

      3、根据聚类结果，重新计算k个簇各自的中心，计算方法是取簇中所有元素各自维度的算术平均数。

      4、将D中全部元素按照新的中心重新聚类。

      5、重复第4步，直到聚类结果不再变化。

      6、将结果输出。
*/

class Kmeans 
{
public:
	Kmeans(int k, const std::vector<vertex>& points, const std::vector<vertex>& centers): k_(k) 
	{
		points_.assign(points.begin(), points.end());
		centers_.assign(centers.begin(), centers.end());
		clusters_.resize(k_);
	}

	Kmeans(int k, int num): k_(k)    // num = 16 * 16
	{
		clusters_.resize(k_);

		// random generate num points
		srand((unsigned)time(NULL));
		for (int i=0; i<num; i++)
		{
			int x = rand() % 16;
			int y = rand() % 16;
			int val = rand() % 255;

			points_.push_back(vertex(x, y, val));
		}

		srand((unsigned)time(NULL));
		for (int j=0; j<k; j++)
		{
			int index = rand() % 256;
			centers_.push_back(points_[index]);
		}

		// print
		for (size_t i=0; i<points_.size(); i++)
		{
			std::cout<<"("<<points_[i].x<<","<<points_[i].y<<","<<points_[i].val<<")";
			if ((i + 1) % 16 == 0)
				std::cout<<std::endl;
		}

		std::cout<<"group number: "<<k_<<std::endl;
		for (size_t i=0; i<centers_.size(); i++)
		{
			std::cout<<"("<<centers_[i].x<<","<<centers_[i].y<<","<<centers_[i].val<<")";
		}
		std::cout<<std::endl;
	}

	void putVertexInClusters()
	{
		for (size_t k=0; k<clusters_.size(); k++)
		{
			clusters_[k].clear();
		}

		for (size_t i=0; i<points_.size(); i++)
		{
			vertex& v = points_[i];
			double min_dis = 9999999999.0;
			int label = 0;
			for (size_t j=0; j<centers_.size(); j++)
			{
				double dis = distanceOf2Vertex(v, centers_[j]);
				if (dis < min_dis)
				{
					label = j;
					min_dis = dis;
				}
			}

			clusters_[label].push_back(v);
		}
	}

	void re_compute_centers()
	{
		centers_.clear();
		for (size_t k=0; k<clusters_.size(); k++)
		{
			std::vector<vertex>& vtx = clusters_[k];
			double sum = 0;
			for (size_t i=0; i<vtx.size(); i++)
			{
				sum += vtx[i].val;
			}

			double mean_val = sum / vtx.size();

			centers_.push_back(vertex(-1, -1, mean_val));
		}
	}

	// re-compute the cost after re-compute new centers
	double re_compute_cost()
	{
		double sum = 0;
		for (size_t k=0; k<clusters_.size(); k++)
		{
			std::vector<vertex>& vtx = clusters_[k];
			for (size_t i=0; i<vtx.size(); i++)
			{
				sum += distanceOf2Vertex(vtx[i], centers_[k]);
			}
		}

		return sum / points_.size();
	}

	void run_k_means()
	{
		double old_cost;
		double new_cost;
		putVertexInClusters();
		new_cost = re_compute_cost();
		re_compute_centers();

		old_cost = new_cost;
		putVertexInClusters();
		new_cost = re_compute_cost();

		int run_number = 2;

		while (new_cost != old_cost)
		{
			run_number++;
			old_cost = new_cost;
			re_compute_centers();
			putVertexInClusters();
			new_cost = re_compute_cost();
		}

		std::cout<<"final cost: "<<new_cost<<" run times: "<<run_number<<std::endl;
		std::cout<<"final centers:"<<std::endl;
		for (size_t i=0; i<centers_.size(); i++)
		{
			std::cout<<centers_[i].val<<std::endl;
		}
	}

private:
	double distanceOf2Vertex(const vertex& v1, const vertex& v2)
	{
		return sqrt(pow(static_cast<double>(v1.val - v2.val), 2));
	}

private:
	int k_;                        // k groups
	std::vector<vertex> points_;   // all vertexs
	std::vector<vertex> centers_;   // k centers
	std::vector<std::vector<vertex> > clusters_;  // k clusters
};

#endif