#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    if (argc != 3)
    {
        ROS_INFO("提交的参数个数不对。");
        return 1;
    }
    
    ros::init(argc,argv,"daBao");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<plumbing_server_client::AddInts>("addInts");
    plumbing_server_client::AddInts ai;
    ai.request.num1 = atoi(argv[1]);
    ai.request.num2 = atoi(argv[2]);
    //调用判断服务器状态的函数
    //方法一：
    // client.waitForExistence();
    //方法二：此方法需要在函数中传入参数，参数为需要等待的服务名
    ros::service::waitForService("addInts");
    bool flag = client.call(ai);
    if (flag)
    {
        ROS_INFO("响应成功！");
        ROS_INFO("响应结果 = %d",ai.response.sum);
    } else {
        ROS_INFO("处理失败...");
    }
    return 0;
}
