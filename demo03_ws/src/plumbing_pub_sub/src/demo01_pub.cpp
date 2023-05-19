#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "erGouZi",ros::init_options::AnonymousName);
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("fang", 10, true);
    std_msgs::String msg;
    ros::Rate rate(1);
    int count = 0;
    while (ros::ok())
    {
        if (count >= 50)
        {
            ros::shutdown();
        }
        
        count++;
        // msg.data = "hello";
        std::stringstream ss;
        ss << "hello ---> " << count;
        msg.data = ss.str();
        // if (count <= 10)
        // {
            pub.publish(msg);
            ROS_INFO("发布的数据是：%s", ss.str().c_str());
        // }
        rate.sleep();
        ros::spinOnce();//官方建议添加，也是为了处理回调函数，但是此例中没有回调函数
        ROS_INFO("一轮回调执行完毕...");
    }
    
    return 0;
}
