#ifndef __ARDUINO_COMMUNICATION__DEVICE_DESCRIPTOR__
#define __ARDUINO_COMMUNICATION__DEVICE_DESCRIPTOR__

#include <string>

namespace arduinocommunication {

	class DeviceDescriptor {
	public:
		DeviceDescriptor(const std::string  & deviceName,
			const unsigned int              & baudRate     = 9600,
			const enum flow_control::type   & flowControl  = flow_control::none,
			const enum parity::type         & parity       = parity::none,
			const enum stop_bits::type      & stopBits     = stop_bits::one,
			const unsigned int              & charSize     = 8);

		const std::string           & getDeviceName()  const;
		const unsigned int            getBaudRate()    const;
		const enum flow_control::type getFlowControl() const;
		const enum parity::type       getParity()      const;
		const unsigned int            getCharSize()    const;

	
	private:
		std::string                   _deviceName;
		const unsigned int            _baudRate;
		const enum flow_control::type _flowControl;
		const enum parity::type       _parity;
		const enum stop_bits::type    _stopBits;
		const unsigned int            _charSize;

	};
	

}

#endif //__ARDUINO_COMMUNICATION__DEVICE_DESCRIPTOR__

