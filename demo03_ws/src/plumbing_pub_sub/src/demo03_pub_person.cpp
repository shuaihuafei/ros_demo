#include "ros/ros.h"
#include "plumbing_pub_sub/Person.h"
/*
    发布方：发布人的消息
        1.包含头文件;
        2.初始化ROS节点；
        3.创建节点句柄；
        4.创建发布者对象；
        5.编写发布逻辑，发布数据。
*/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ROS_INFO("这是消息发布方");
    ros::init(argc,argv,"banZhuRen");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<plumbing_pub_sub::Person>("liaotian",10);
    plumbing_pub_sub::Person person;
    person.name = "张三";
    person.age = 1;
    person.height = 1.73;
    ros::Rate rate(1);
    while(ros::ok())
    {
        person.age += 1;
        pub.publish(person);
        ROS_INFO("分布的消息：%s,%d,%.2f",person.name.c_str(),person.age,person.height);
        rate.sleep();
        ros::spinOnce();
    }
    return 0;
}
