#include "base_bridge_ros_orocos.hpp"


BaseBridgeRosOrocos::BaseBridgeRosOrocos(const string& name) :  TaskContext(name, PreOperational)
{
	m_srv_enable_navigation = m_nh.advertiseService("enable_navigation_mode", &BaseBridgeRosOrocos::enableNavigationModeCallback, this);
	m_srv_disable_navigation = m_nh.advertiseService("disable_navigation_mode", &BaseBridgeRosOrocos::disableNavigationModeCallback, this);
}

BaseBridgeRosOrocos::~BaseBridgeRosOrocos()
{
	m_srv_enable_navigation.shutdown();
	m_srv_disable_navigation.shutdown();
}

bool BaseBridgeRosOrocos::configureHook()
{
	//Operations
	if(this->getPeer("executive"))
	{
		std::cout << "get operation doNavigation" << std::endl;
		m_enable_navigation = this->getPeer("executive")->getOperation("doNavigation");

		std::cout << "get operation doNotNavigation" << std::endl;
		m_disable_navigation = this->getPeer("executive")->getOperation("doNotNavigation");
	}

	return TaskContext::configureHook();
}

bool BaseBridgeRosOrocos::startHook()
{
	return TaskContext::startHook();
}

void BaseBridgeRosOrocos::updateHook()
{
	TaskContext::updateHook();

	ros::spinOnce();
}

void BaseBridgeRosOrocos::stopHook()
{
	TaskContext::stopHook();
}

void BaseBridgeRosOrocos::cleanupHook()
{
	TaskContext::cleanupHook();
}

bool BaseBridgeRosOrocos::enableNavigationModeCallback(std_srvs::Empty::Request &req, std_srvs::Empty::Response &res)
{
	if(!m_enable_navigation.ready())
	{
		std::cout << "operation not available" << std::endl;
		return false;
	}

	m_enable_navigation();

	return true;
}

bool BaseBridgeRosOrocos::disableNavigationModeCallback(std_srvs::Empty::Request &req, std_srvs::Empty::Response &res)
{
	if(!m_disable_navigation.ready())
	{
		std::cout << "operation not available" << std::endl;
		return false;
	}

	m_disable_navigation();

	return true;
}

ORO_CREATE_COMPONENT( BaseBridgeRosOrocos )
