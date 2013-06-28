#include "DeviceDescriptor.h"

namespace arduinocommunication {

	DeviceDescriptor::DeviceDescriptor(const std::string  & deviceName,
			const unsigned int              & baudRate,
			const enum flow_control::type   & flowControl,
			const enum parity::type         & parity,
			const enum stop_bits::type      & stopBits,
			const unsigned int              & charSize) :
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
	
	const unsigned int DeviceDescriptor::getBaudRate() const
	{
		return _baudRate;
	}
	
	const enum flow_control::type DeviceDescriptor::getFlowControl() const
	{
		return _flowControl;
	}
	
	const enum parity::type DeviceDescriptor::getParity() const
	{
		return _parity;
	}
	
	const unsigned int DeviceDescriptor::getCharSize() const
	{
		return _charSize;
	}
	
}

