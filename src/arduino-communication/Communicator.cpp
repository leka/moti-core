#include "Communicator.h"

#include <iostream>

namespace arduinocommunication {

	Communicator::Communicator(const DeviceDescriptor & deviceDescriptor) :
		_ioService(),
		_serialPort(_ioService)
	{
		
		// We initialize the serial port
		_serialPort.open(deviceDescriptor.getDeviceName());
		
		if (_serialPort.is_open()) {
			
			_serialPort.set_option(boost::asio::serial_port::baud_rate(deviceDescriptor.getBaudRate()));
			_serialPort.set_option(boost::asio::serial_port::flow_control(deviceDescriptor.getFlowControl()));
			_serialPort.set_option(boost::asio::serial_port::parity(deviceDescriptor.getParity()));
			_serialPort.set_option(boost::asio::serial_port::stop_bits(deviceDescriptor.getStopBits()));
			_serialPort.set_option(boost::asio::serial_port::character_size(deviceDescriptor.getCharSize()));
			
		}
		else {
			throw 2;
		}

		// We wait on the start of the communication
		char bufferTemp = ' ';
		short maxAttemptCount = 0;
		do {
			boost::asio::read(_serialPort, boost::asio::buffer(&bufferTemp, 1));
		}
		while (bufferTemp != 42 && maxAttemptCount < 100);

		if (maxAttemptCount == 100) {
			throw 3;
		}
	}
	
	Communicator::~Communicator()
	{
		
	}
	
	void Communicator::addListener(IDataListener * listener)
	{
		_listenerList.push_back(listener);
	}
	
	void Communicator::getData()
	{
		//// We will send data to the arduino and it will respond
		////

		//// So we send our command
		// We construct our request
		char dataHeader[1] = { 42 };

		char dataFooter[1] = { 41 };

		std::vector<boost::asio::const_buffer> dataSet;
		dataSet.push_back(boost::asio::buffer(dataHeader));
		dataSet.push_back(boost::asio::buffer(dataFooter));

		// Then we send it (synchronized write)
		size_t byte_sent = boost::asio::write(_serialPort, dataSet);

		//// Then we read the data back

		// We wait on the start of the communication
		char bufferTemp = ' ';
		short maxAttemptCount = 0;
		do {
			boost::asio::read(_serialPort, boost::asio::buffer(&bufferTemp, 1));
			maxAttemptCount++;
		}
		while (bufferTemp != 42 && maxAttemptCount < 100);

		if (maxAttemptCount == 100) {
			throw 4;
		}

		boost::array<short, 6> dataBack;
		size_t byte_read = boost::asio::read(_serialPort, boost::asio::buffer(dataBack));

		Int3 acc (dataBack[0], dataBack[1], dataBack[2]);
		Int3 gyro(dataBack[3], dataBack[4], dataBack[5]);
		
		notify(acc, gyro);
	}

	void Communicator::notify(const common::Int3 & acc, const common::Int3 & gyro) {

		for (std::vector<IDataListener *>::iterator it = _listenerList.begin(); it != _listenerList.end(); it++) {
			(*it)->setAcceleration(acc);
			(*it)->setGyro(gyro);
			(*it)->notify();
		}

	}

}

