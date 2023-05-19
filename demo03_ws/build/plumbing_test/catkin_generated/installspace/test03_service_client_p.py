#!/usr/bin/env python3

import rospy
from turtlesim.srv import Spawn,SpawnRequest,SpawnResponse
if __name__ == "__main__":
    rospy.init_node("service_call_p")
    client = rospy.ServiceProxy("/spawn",Spawn)
    # 4.组织数据并发送请求；
    # 4-1.组织数据
    request = SpawnRequest()
    request.x = 4.5
    request.y = 2.0
    request.theta = -3
    request.name = "turtle3"
    # 4-2.判断服务器状态并发送
    client.wait_for_service()
    try:
        response = client.call(request)
        rospy.loginfo("生成乌龟的名字叫：%s",response.name)
    except Exception as e:
        rospy.logerr("请求处理异常！！！")