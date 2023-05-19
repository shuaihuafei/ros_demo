#include <ros/ros.h>
// PCL specific includes
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/ros/conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
// 关于平面分割的头文件
#include <pcl/sample_consensus/model_types.h>  //分割模型的头文件
#include <pcl/sample_consensus/method_types.h> //采样一致性的方法
#include <pcl/segmentation/sac_segmentation.h> //ransac分割法

ros::Publisher pub;

void cloud_cb(const sensor_msgs::PointCloud2ConstPtr &input)
{
    // 将点云格式为sensor_msgs/PointCloud2 格式转为 pcl/PointCloud
    pcl::PointCloud<pcl::PointXYZ> cloud;
    pcl::fromROSMsg(*input, cloud); // 关键的一句数据的转换

    pcl::ModelCoefficients coefficients; // 申明模型的参数
    pcl::PointIndices inliers;           // 申明存储模型的内点的索引
    // 创建一个分割方法
    pcl::SACSegmentation<pcl::PointXYZ> seg;
    // 这一句可以选择最优化参数的因子
    seg.setOptimizeCoefficients(true);
    // 以下都是强制性的需要设置的
    seg.setModelType(pcl::SACMODEL_PLANE); // 平面模型
    seg.setMethodType(pcl::SAC_RANSAC);    // 分割平面模型所使用的分割方法
    seg.setDistanceThreshold(0.01);        // 设置最小的阀值距离

    seg.setInputCloud(cloud.makeShared()); // 设置输入的点云
    seg.segment(inliers, coefficients);    // cloud.makeShared() 创建一个 boost shared_ptr

    // 把提取出来的内点形成的平面模型的参数发布出去
    pcl_msgs::ModelCoefficients ros_coefficients;
    pcl_conversions::fromPCL(coefficients, ros_coefficients);
    pub.publish(ros_coefficients);
}

int main(int argc, char **argv)
{
    // Initialize ROS
    ros::init(argc, argv, "my_pcl_tutorial");
    ros::NodeHandle nh;

    // Create a ROS subscriber for the input point cloud
    ros::Subscriber sub = nh.subscribe("/camera/depth/points", 1, cloud_cb);

    // Create a ROS publisher for the output model coefficients
    pub = nh.advertise<pcl_msgs::ModelCoefficients>("output", 1);

    // Spin
    ros::spin();
}