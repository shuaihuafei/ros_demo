#!/usr/bin/env python3

import rospy

if __name__ =="__main__":
    rospy.init_node("get_param_p")
    radius = rospy.get_param("radius_p", 0.5)
    radius2 = rospy.get_param("radius_p_xxx", 0.5)
    rospy.loginfo("radius = %.2f",radius)
    rospy.loginfo("radius2 = %.2f",radius2)

    names = rospy.get_param_names()
    for name in names:
        rospy.loginfo("name = %s",name)

    