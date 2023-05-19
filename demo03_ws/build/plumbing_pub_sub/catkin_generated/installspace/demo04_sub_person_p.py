#!/usr/bin/env python3
import rospy
from plumbing_pub_sub.msg import Person

def doPerson(p):
    rospy.loginfo("小伙子的数据：%s,%d,%.2f",p.name,p.age,p.height)

if __name__ == "__main__":
    rospy.init_node("daYe")
    sub = rospy.Subscriber("jiaoSheTou",Person,doPerson)
    rospy.spin()