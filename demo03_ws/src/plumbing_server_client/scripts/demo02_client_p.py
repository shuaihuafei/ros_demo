#! /usr/bin/env python

import rospy
from plumbing_server_client.srv import *
import sys

if __name__ == "__main__":
    if len(sys.argv) != 3:
        rospy.logerr("传入的参数个数不对")
        sys.exit(1)
    rospy.init_node("erHei")
    client = rospy.ServiceProxy("addInts",AddInts)
    num1 = int(sys.argv[1])
    num2 = int(sys.argv[2])
    # 等待服务启动
    # 方法一：通过client.wait_for_service()
    # 方法二：通过rospy.wait_for_service("addInts")，
    # 但是通过rospy后面函数要加话题名作为参数
    rospy.wait_for_service("addInts")
    response = client.call(num1,num2)
    rospy.loginfo("响应的数据：%d",response.sum)