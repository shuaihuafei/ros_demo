#!/usr/bin/env python3
import rospy

if __name__ == "__main__":
    rospy.init_node("param_set_p")
    rospy.set_param("type_p","xiaohuangche")
    rospy.set_param("radius_p",0.15)
    # 修改的语句与新增的语句是一样的
    rospy.set_param("radius_p",0.15)