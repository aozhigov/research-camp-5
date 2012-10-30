#pragma once

/* OROCOS include files */
#include <rtt/TaskContext.hpp>
#include <rtt/Logger.hpp>
#include <rtt/Port.hpp>
#include <rtt/Activity.hpp>
#include <rtt/RTT.hpp>
#include <rtt/Property.hpp>
#include <rtt/PropertyBag.hpp>
#include <rtt/Time.hpp>
#include <ocl/Component.hpp>

#include <ros/ros.h>
#include <std_srvs/Empty.h>


using namespace RTT;
using namespace std;

class BaseBridgeRosOrocos: public TaskContext
{
  public:
    BaseBridgeRosOrocos(const string& name);
    virtual ~BaseBridgeRosOrocos();

    bool enableNavigationModeCallback(std_srvs::Empty::Request &req, std_srvs::Empty::Response &res);
    bool disableNavigationModeCallback(std_srvs::Empty::Request &req, std_srvs::Empty::Response &res);

  protected:
    virtual bool configureHook();
    virtual bool startHook();
    virtual void updateHook();
    virtual void stopHook();
    virtual void cleanupHook();

  private:

    OperationCaller<void(void)> m_enable_navigation;
    OperationCaller<void(void)> m_disable_navigation;

	ros::NodeHandle m_nh;

	ros::ServiceServer m_srv_enable_navigation;
	ros::ServiceServer m_srv_disable_navigation;
};

