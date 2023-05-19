#include "ros/ros.h"
/*
    需求：修改参数服务器中 turtlesim 背景色相关的参数

    1.初始化ros节点；
    2.不一定需要创建节点句柄（和后续API相关）；
    3.修改参数
*/
int main(int argc, char *argv[])
{
    ros::init(argc,argv,"change_bgColor");
    // 3.修改参数有两种方式
    // 3-1.如果不创建节点句柄，可以直接ros::param::set来设置参数的值
    // ros::param::set("/turtlesim/background_r",0);
    // ros::param::set("/turtlesim/background_g",0);
    // ros::param::set("/turtlesim/background_b",0);
    // 3-2.通过创建节点句柄来设置参数
    // 3-2-1.如果要设置/turtlesim/background_r这种比较长的，可以在创建节点句柄时先设置一下命名空间
    // ros::NodeHandle nh("turtlesim");
    // nh.setParam("background_r",255);
    // nh.setParam("background_g",255);
    // nh.setParam("background_b",255);
    // 3-2-2.如果要设置/turtlesim/background_r这种比较长的，也可以在直接在设置参数时一起创建命名空间
    ros::NodeHandle nh;
    nh.setParam("/turtlesim/background_r",0);
    nh.setParam("/turtlesim/background_g",50);
    nh.setParam("/turtlesim/background_b",100);
    return 0;
}
