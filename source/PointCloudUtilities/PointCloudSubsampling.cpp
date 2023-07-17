#include "PointCloudSubsampling.h"

PointCloudSubsampling::PointCloudSubsampling()
{
	encoder = new pcl::io::OctreePointCloudCompression<pcl::PointXYZRGB>(
		pcl::io::MANUAL_CONFIGURATION, false, 0.001, 1, true, 1, true, 6
	);
}

PointCloudSubsampling::~PointCloudSubsampling()
{
	delete encoder;
}

void PointCloudSubsampling::Save(char* path) {

}