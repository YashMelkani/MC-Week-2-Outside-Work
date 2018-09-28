/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Rise.h"
#include "iostream"
using namespace std;

Rise::Rise() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::m_lift);
}

// Called just before this Command runs the first time
void Rise::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Rise::Execute() {
	Robot::m_lift->move(Robot::m_oi.getJoy());
}

// Make this return true when this Command no longer needs to run execute()
bool Rise::IsFinished() {
	if(Robot::m_lift->getLift()->GetSensorCollection().IsFwdLimitSwitchClosed()){
		return true;
	}
	else{
		return false;
	}
}

// Called once after isFinished returns true
void Rise::End() {
	double height = Robot::m_lift->getLift()->GetSensorCollection().GetQuadraturePosition();
	height = height/4096; // assume 1/4096 converts ticks to height
	std::cout<<"Height: " << height <<std::endl;

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Rise::Interrupted() {

}
