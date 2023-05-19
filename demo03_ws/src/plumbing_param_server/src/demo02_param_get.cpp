#include "ros/ros.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"get_param_c");
    ros::NodeHandle nh;

    // 1.param(键,默认值) 
    //   存在，返回对应结果，否则返回默认值
    double radius = nh.param("radius",0.5);
    ROS_INFO("radius = %.2f",radius);

    // 2.getParam(键,存储结果的变量)
    //   存在,返回 true,且将值赋值给参数2
    //   若果键不存在，那么返回值为 false，且不为参数2赋值
    double radius2 = 0.0;
    bool result2 = nh.getParam("radius",radius2);
    if(result2)
    {
        ROS_INFO("获取的半径是：%.2f",radius2);
    } else {
        ROS_INFO("被查询的变量不存在。");
    }

    // 3.getParamCached键,存储结果的变量)--提高变量获取效率
    //   存在,返回 true,且将值赋值给参数2
    //   若果键不存在，那么返回值为 false，且不为参数2赋值
    double radius3 = 0.0;
    bool result3 = nh.getParamCached("radius",radius3);
    if(result3)
    {
        ROS_INFO("获取的半径是：%.2f",radius3);
    } else {
        ROS_INFO("被查询的变量不存在。");
    }

    // 4.getParamNames(std::vector<std::string>)
    //   获取所有的键,并存储在参数 vector 中 
    std::vector<std::string> names;
    nh.getParamNames(names);
    for (auto &&name : names)
    {
        ROS_INFO("遍历的元素：%s",name.c_str());
    }
    
    // 5.hasParam(键)
    //   是否包含某个键，存在返回 true，否则返回 false
    bool flag1 = nh.hasParam("radius");
    bool flag2 = nh.hasParam("radiusxx");
    ROS_INFO("radius存在吗？ %d", flag1);
    ROS_INFO("radiusxx存在吗？ %d", flag2);

    // 6.searchParam(参数1，参数2)
    //   搜索键，参数1是被搜索的键，参数2存储搜索结果的变量
    std::string key;
    nh.searchParam("radiusx",key);
    ROS_INFO("搜索的结果：%s", key.c_str());

    return 0;
}
