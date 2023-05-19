#include "ros/ros.h"
#include "nodelet/nodelet.h"
#include "pluginlib/class_list_macros.h"
#include "std_msgs/Float64.h"

/*
    需求：首先，需要订阅一个浮点数据；然后，将订阅的数据与参数服务器的制定参数相加；最后，将最终结果发布
    流程：
        1.确定需要的变量：订阅对象，发布对象，存储参数的变量；
        2.获取 NodleHandle;
        3.通过 NodleHandle 创建订阅对象和发布对象，解析参数；
        4.订阅对象的回调函数需要处理数据，并通过发布对象发布。
*/
namespace my_nodelet
{
    class MyPlus : public nodelet::Nodelet
    {
    public:
        MyPlus()
        {
            value = 0.0;
        }
        void onInit()
        {
            // 获取 NodeHandle
            ros::NodeHandle &nh = getPrivateNodeHandle();
            // 从参数服务器获取参数
            nh.getParam("value", value);
            // 创建发布与订阅对象
            pub = nh.advertise<std_msgs::Float64>("out", 100);
            sub = nh.subscribe<std_msgs::Float64>("in", 100, &MyPlus::doCb, this);
        }
        // 回调函数
        void doCb(const std_msgs::Float64::ConstPtr &p)
        {
            double num = p->data;
            // 数据处理
            double result = num + value;
            std_msgs::Float64 r;
            r.data = result;
            // 发布
            pub.publish(r);
        }

    private:
        ros::Publisher pub;
        ros::Subscriber sub;
        double value;
    };
};

PLUGINLIB_EXPORT_CLASS(my_nodelet::MyPlus, nodelet::Nodelet)