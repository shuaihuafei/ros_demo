/***********************************************************
关于使用sensor_msgs/PointCloud2，
***********************************************************/

#include <ros/ros.h>
// PCL 的相关的头文件
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
// 滤波的头文件
#include <pcl/filters/voxel_grid.h>
// 申明发布器
ros::Publisher pub;
// 回调函数
void cloud_cb(const sensor_msgs::PointCloud2ConstPtr &input) // 特别注意的是这里面形参的数据格式
{
  // 声明存储原始数据与滤波后的数据的点云的格式
  pcl::PCLPointCloud2 *cloud = new pcl::PCLPointCloud2; // 原始的点云的数据格式
  pcl::PCLPointCloud2ConstPtr cloudPtr(cloud);
  pcl::PCLPointCloud2 cloud_filtered; // 存储滤波后的数据格式

  // 转化为PCL中的点云的数据格式
  pcl_conversions::toPCL(*input, *cloud);

  // 进行一个滤波处理
  pcl::VoxelGrid<pcl::PCLPointCloud2> sor; // 实例化滤波
  sor.setInputCloud(cloudPtr);             // 设置输入的滤波
  sor.setLeafSize(0.1, 0.1, 0.1);          // 设置体素网格的大小
  sor.filter(cloud_filtered);              // 存储滤波后的点云

  // 再将滤波后的点云的数据格式转换为ROS 下的数据格式发布出去
  sensor_msgs::PointCloud2 output;                  // 声明的输出的点云的格式
  pcl_conversions::fromPCL(cloud_filtered, output); // 第一个参数是输入，后面的是输出

  // 发布命令
  pub.publish(output);
}

int main(int argc, char **argv)
{
  // 初始化 ROS节点
  ros::init(argc, argv, "my_pcl_tutorial");
  ros::NodeHandle nh; // 声明节点的名称

  // 为接受点云数据创建一个订阅节点
  ros::Subscriber sub = nh.subscribe("/camera/depth/points", 100, cloud_cb);

  // 创建ROS的发布节点
  pub = nh.advertise<sensor_msgs::PointCloud2>("output", 100);

  // 回调
  ros::spin();
}