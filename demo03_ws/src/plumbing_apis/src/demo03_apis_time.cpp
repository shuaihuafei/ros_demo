#include "ros/ros.h"

void cb(const ros::TimerEvent& event)
{
    ROS_INFO("-------------------");
    ROS_INFO("函数被调用的时刻：%.2f",event.current_real.toSec());
}
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"hello_time");
    ros::NodeHandle nh; //注意：必须。否则会导致时间API调用失败（在NodeHandle会初始化时间操作）
    // 参考系： 1970年01月01日 00:00:00
    ros::Time right_now = ros::Time::now();
    ROS_INFO("当前时刻：%.2f",right_now.toSec());
    ROS_INFO("当前时刻：%d",right_now.sec);

    ros::Time t1(20,312345674);
    ros::Time t2(100.35);
    ROS_INFO("t1 = %.2f",t1.toSec());
    ROS_INFO("t2 = %.2f",t2.toSec());

    ROS_INFO("-------------------持续时间-------------------");
    ros::Time start = ros::Time::now();
    ROS_INFO("开始休眠:%.2f",start.toSec());
    ros::Duration du(4.5);
    // du.sleep();
    ros::Time end = ros::Time::now();
    ROS_INFO("休眠结束:%.2f",end.toSec());

    ROS_INFO("-------------------时间运算-------------------");
    ros::Time begin = ros::Time::now();
    ros::Duration du1(5);
    ros::Time stop = begin - du1;
    ROS_INFO("开始时刻：%.2f",begin.toSec());
    ROS_INFO("结束时刻：%.2f",stop.toSec());

    ROS_INFO("-------------------定时器-------------------");
    // ros::Timer timer = nh.createTimer(ros::Duration(1),cb);
    // ros::Timer timer = nh.createTimer(ros::Duration(1),cb,true);
    ros::Timer timer = nh.createTimer(ros::Duration(1),cb,false,false);
    timer.start();
    ros::spin();

    return 0;
}
