#include "DeviceDescriptor.h"

using namespace boost::asio;

namespace arduinocommunication {

	DeviceDescriptor::DeviceDescriptor(const std::string  & deviceName,
			const unsigned int                      & baudRate,
			const serial_port::flow_control::type   & flowControl,
			const serial_port::parity::type         & parity,
			const serial_port::stop_bits::type      & stopBits,
			const unsigned int                      & charSize) :
		_deviceName(deviceName),
		_baudRate(baudRate),
		_flowControl(flowControl),
		_parity(parity),
		_stopBits(stopBits),
		_charSize(charSize)
	{}
	
	const std::string & DeviceDescriptor::getDeviceName() const
	{
		return _deviceName;
	}
	
	unsigned int DeviceDescriptor::getBaudRate() const
	{
		return _baudRate;
	}
	
	serial_port::flow_control::type DeviceDescriptor::getFlowControl() const
	{
		return _flowControl;
	}
	
	serial_port::parity::type DeviceDescriptor::getParity() const
	{
		return _parity;
	}

	serial_port::stop_bits::type DeviceDescriptor::getStopBits() const
	{
		return _stopBits;
	}
	
	unsigned int DeviceDescriptor::getCharSize() const
	{
		return _charSize;
	}
	
}

