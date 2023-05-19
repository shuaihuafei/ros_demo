#include "ros/ros.h"
#include "std_msgs/String.h"

void doMsg(const std_msgs::String::ConstPtr &msg)
{
    ROS_INFO("翠花订阅的数据:%s",msg->data.c_str());
}
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc,argv,"cuihua");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("fang",10,doMsg);
    //ros::spin()的作用是让程序回头，频繁调用回调函数doMsg
    ros::spin();
    ROS_INFO("spin后的语句");
    return 0;
}
