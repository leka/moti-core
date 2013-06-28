#include "Communicator.h"

#include <iostream>

namespace arduinocommunication {

	Communicator::Communicator(const DeviceDescriptor & deviceDescriptor) :
		_ioService(),
		_serialPort(_ioService)
	{
		
		_serialPort.open(deviceDescriptor.getDeviceName());
		
		if (_serialPort.is_open()) {
			
			m_SerialPort.set_option(boost::asio::serial_port::baud_rate(deviceDescriptor.getBaudRate()));
			m_SerialPort.set_option(boost::asio::serial_port::flow_control(deviceDescriptor.getFlowControl()));
			m_SerialPort.set_option(boost::asio::serial_port::parity(deviceDescriptor.getParity()));
			m_SerialPort.set_option(boost::asio::serial_port::stop_bits(deviceDescriptor.getStopBits()));
			m_SerialPort.set_option(boost::asio::serial_port::character_size(deviceDescriptor.getCharSize()));
			
		}
		else {
			throw 2;
		}
		
	}
	
	Communicator::~Communicator()
	{
		
	}
	
	void Communicator::addNotifier(IDataNotifier * notifier)
	{
		_notifierList.push_back(notifier);
	}
	
	void Communicator::getData()
	{
		
	}

}

