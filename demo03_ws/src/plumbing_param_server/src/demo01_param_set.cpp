#include "ros/ros.h"


int main(int argc, char *argv[])
{
    ros::init(argc,argv,"set_param_c");
    ros::NodeHandle nh;
    //参数增-----------------------------
    //方案1：通过句柄节点来设置参数
    nh.setParam("type","xiaoHuang");
    nh.setParam("radius",0.15);
    //方案2：通过ros::param来设置参数
    ros::param::set("type_param","xiaoBai");
    ros::param::set("radius_param",0.15);
    //参数改-----------------------------
    //方案1：通过句柄节点来修改参数
    nh.setParam("radius",0.2);  //本质相当于就是将之前radius中的参数覆盖了
    //方案2：通过ros::param来设置参数
    ros::param::set("radius_param",0.25);

    return 0;
}
