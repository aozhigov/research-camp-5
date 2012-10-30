#!/usr/bin/python
import time

import roslib
roslib.load_manifest('raw_script_server')
import rospy
import actionlib

from raw_script_server.msg import *
from simple_script_server import *

sss = simple_script_server()

## Main routine for running the script server
#
if __name__ == '__main__':
    rospy.init_node('script_server_test')
    
    
    sss.move("arm", "initposition")   
    sss.move("arm", "calibration_pose1")
    raw_input("enter: ")    
    sss.move("arm", "calibration_pose2")
    raw_input("enter: ")    
    sss.move("arm", "calibration_pose3")
    raw_input("enter: ")    
    sss.move("arm", "initposition")   
   
    #raw_input("enter: ")    
    
    #sss.move("arm", [0.4, 0.0, 0.15, 0, ((math.pi/2) + (math.pi/4)), 0, "/base_link"])

    #raw_input("enter: ")    
    
    #sss.move("arm", "zeroposition")
