#pragma once

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/compression/octree_pointcloud_compression.h>

class PointCloudSubsampling
{
public:
	PointCloudSubsampling();
	~PointCloudSubsampling();
	void Save(char* path);
private:
	pcl::io::OctreePointCloudCompression<pcl::PointXYZRGB>* encoder;
};
