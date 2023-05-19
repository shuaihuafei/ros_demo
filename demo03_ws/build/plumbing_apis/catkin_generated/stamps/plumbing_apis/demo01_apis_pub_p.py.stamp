#! /usr/bin/env python
import rospy
from std_msgs.msg import String

def cb():
    rospy.loginfo("节点正在被关闭。。。")

if __name__ == "__main__":
    rospy.init_node("sanDai")
    pub = rospy.Publisher("che",String,queue_size=10)
    msg = String()
    rate = rospy.Rate(1)
    count = 0
    while not rospy.is_shutdown():
        count += 1
        if count <= 5:
            msg.data = "hello" + str(count)
            pub.publish(msg)
            rospy.loginfo("发布的数据：%s",msg.data)
        else:
            # 此语句的意思是在程序关闭的时候执行cb，本身并不具备关闭节点的功能。
            # rospy.signal_shutdown("")才具备关闭节点的功能
            rospy.on_shutdown(cb)
            rospy.signal_shutdown("shutdown")
        rate.sleep()
    