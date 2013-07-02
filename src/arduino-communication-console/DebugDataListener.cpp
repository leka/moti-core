#include "DebugDataListener.h"

#include <iostream>

namespace arduinocommunicationconsole {

	DebugDataListener::DebugDataListener() {

	}

	DebugDataListener::~DebugDataListener() {
		
	}

	void DebugDataListener::setAcceleration(const common::Int3 & acceleration) {
		std::cout << "setAcceleration(" 
			<< acceleration._x << "; " 
			<< acceleration._y << "; " 
			<< acceleration._z << ")" << std::endl;
	}

	void DebugDataListener::setVolume(const int volume) {
		std::cout << "setVolume(" 
			<< volume << ")" << std::endl;
	}

	void DebugDataListener::setGyro(const common::Int3 & gyro) {
		std::cout << "setGyro(" 
			<< gyro._x << "; " 
			<< gyro._y << "; " 
			<< gyro._z << ")" << std::endl;
	}

	void DebugDataListener::notify() {
		std::cout << "Notified for new data" << std::endl;
	}

}