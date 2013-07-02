#ifndef __ARDUINO_COMMUNICATION__DEVICE_DESCRIPTOR__
#define __ARDUINO_COMMUNICATION__DEVICE_DESCRIPTOR__

#include <boost/asio.hpp>

#include <string>

namespace arduinocommunication {

	class DeviceDescriptor {
	public:
		DeviceDescriptor(const std::string                       & deviceName,
			const unsigned int                                   & baudRate     = 9600,
			const boost::asio::serial_port::flow_control::type   & flowControl  = boost::asio::serial_port::flow_control::none,
			const boost::asio::serial_port::parity::type         & parity       = boost::asio::serial_port::parity::none,
			const boost::asio::serial_port::stop_bits::type      & stopBits     = boost::asio::serial_port::stop_bits::one,
			const unsigned int                                   & charSize     = 8);

		const std::string                            & getDeviceName()  const;
		unsigned int                                   getBaudRate()    const;
		boost::asio::serial_port::flow_control::type   getFlowControl() const;
		boost::asio::serial_port::parity::type         getParity()      const;
		boost::asio::serial_port::stop_bits::type      getStopBits()    const;
		unsigned int                                   getCharSize()    const;

	
	private:
		std::string                                        _deviceName;
		const unsigned int                                 _baudRate;
		const boost::asio::serial_port::flow_control::type _flowControl;
		const boost::asio::serial_port::parity::type       _parity;
		const boost::asio::serial_port::stop_bits::type    _stopBits;
		const unsigned int                                 _charSize;

	};
	

}

#endif //__ARDUINO_COMMUNICATION__DEVICE_DESCRIPTOR__

