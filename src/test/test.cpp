#include <iostream>
#include <string>
#include <libusb-1.0/libusb.h>

int main(int argc, char * argv[]) {

	libusb_device ** devices = NULL;
	libusb_context * context = NULL;

	int nbDevices = 0;
	int errorCode = 0;

	errorCode = libusb_init(&context);

	if (errorCode < 0) {
		std::cout << "Error" << std::endl;
	}

	nbDevices = libusb_get_device_list(context, &devices);

	for (int i = 0; i < nbDevices; i++) {
		libusb_device_descriptor descriptor;
		libusb_get_device_descriptor(devices[i], &descriptor);
		std::cout << "--- Device : " << i << std::cout;
		std::cout << descriptor.idVendor << std::endl;
		std::cout << descriptor.idProduct << std::endl;

	}


	return 0;
}
