#ifndef __ARDUINO_COMMUNICATION__DEVICE_DESCRIPTOR__
#define __ARDUINO_COMMUNICATION__DEVICE_DESCRIPTOR__

namespace arduinocommunication {

	class DeviceDescriptor {
	public:
		DeviceDescriptor(const int idVendor, const int idProduct);

		int getIdVendor() const;		
		int getIdProduct() const;

	
	private:
		int _idVendor;
		int _idProduct;

	};

}

#endif //__ARDUINO_COMMUNICATION__DEVICE_DESCRIPTOR__

