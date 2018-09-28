/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Lift.h"
#include "../RobotMap.h"
#include "Commands/Rise.h"

Lift::Lift() : Subsystem("Lift"), lift(new TalonSRX(1)) {
	lift->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative,0,10);
	lift->SetSelectedSensorPosition(0,0,10);
}

void Lift::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new Rise());
}


void Lift::move(Joystick* a){
	lift->Set(ControlMode::PercentOutput, a->GetY());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

TalonSRX* Lift::getLift(){
	return lift;
}
