#include "Communicator.h"

#include <libusb-1.0/libusb.h>
#include <iostream>

namespace arduinocommunication {

	Communicator::Communicator(const DeviceDescriptor & deviceDescriptor) :
		_notifiers(),
		_context(NULL),
		_handle(NULL)
	{
		// Returned code to check errors
		int error_code = 0;
		
		error_code = libusb_init(&_context);
		if (error_code) {
			throw common::Exception();
		}
		
		libusb_device ** deviceList  = NULL;
		libusb_device  * device      = NULL;
		
		ssize_t cnt = libusb_get_device_list(_context, &deviceList);
		
		if (cnt < 0) { // Error
			throw common::Exception();
		}
		if (cnt == 0) { // No available device
			throw common::Exception();
		}
		
		for (ssize_t i = 0; i < cnt; i++) {
			libusb_device * tmp = deviceList[i];
			if (checkDevice(tmp, deviceDescriptor)) {
				device = tmp;
				break;
			}
		}
		
		if (device == NULL) {
			throw common::Exception();
		}
		
		error_code = libusb_open(device, &_handle);		
		
		if (error_code) {
			throw common::Exception();
		}
		
	}
	
	Communicator::~Communicator()
	{
	
		// First release the handle (it release the device too
		libusb_close(_handle);
		
		// Then close the libusb library
		libusb_exit(_context);
	}
	
	void Communicator::addNotifier(IDataNotifier * notifier)
	{
		_notifiers.push_back(notifier);
	}
	
	void Communicator::getData()
	{
		int error_code = 0;
		unsigned char * string = new unsigned char[64];
		int received = 0;
		
		error_code = libusb_bulk_transfer(_handle, LIBUSB_ENDPOINT_IN, string, 64, &received, 0);
		
		if (error_code) {
			std::cout << "[Error] bulk : " << error_code << std::endl;
		}
		std::cout << "Read : " << received << std::endl;
		std::cout << string << std::endl;
		
	}


	bool Communicator::checkDevice(libusb_device * device, const DeviceDescriptor & deviceDescriptor)
	{
		int error_code = 0;
		libusb_device_descriptor descriptor;
		error_code = libusb_get_device_descriptor(device, &descriptor);
		
		if (error_code) {
			throw common::Exception();
		}
		
		return ((deviceDescriptor.getIdProduct() == descriptor.idProduct) && (deviceDescriptor.getIdVendor() == descriptor.idVendor));
	}

}

