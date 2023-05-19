#!/usr/bin/env python3
import os
import sys

import rospy
from std_msgs.msg import String

# 设置临时环境变量
# 路径写死，影响了代码的可移植性
# sys.path.insert(0,"/home/shuai/demo03_ws/src/plumbing_pub_sub/scripts")
# 优化，可以动态获取路径
path = os.path.abspath(".")
sys.path.insert(0,path + "/src/plumbing_pub_sub/scripts")

import tools

if __name__ == "__main__":
    rospy.init_node("sanDai")
    # 异常：MeduleNotFoundError: No module names 'tools'
    '''
        原因：rosrun执行是，参考路径是工作空间的路径，在工作空间下无法查找依赖的模块
        解决：可以声明python的环境变量，当依赖某个模块时，先去制定的环境变量中查找依赖
    '''
    # path = os.path.abspath(".")
    # rospy.loginfo("执行时参考的路径：%s",path)
    rospy.loginfo("num = %d",tools.num)
    pub = rospy.Publisher("che",String,queue_size=10)
    msg = String()
    rate = rospy.Rate(1)
    count = 0
    # rospy.sleep(3)
    while not rospy.is_shutdown():
        count += 1
        msg.data = "hello" + str(count)
        pub.publish(msg)
        rospy.loginfo("发布的数据：%s", msg.data)
        rate.sleep()