#!/usr/bin/env python3
import rospy
from plumbing_server_client.srv import AddInts,AddIntsRequest,AddIntsResponse
# from plumbing_server_client.srv import *

def doNum(request):
    num1 = request.num1
    num2 = request.num2
    sum = num1 + num2
    response = AddIntsResponse()
    response.sum = sum
    rospy.loginfo("服务器解析的数据num1 = %d, num2 = %d, 响应的结果：sum = %d",num1,num2,sum)
    return response

if __name__ == "__main__":
    rospy.init_node("heiShui")
    server = rospy.Service("addInts",AddInts,doNum)
    rospy.loginfo("服务器已经启动了")
    rospy.spin()